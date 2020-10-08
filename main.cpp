#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

int main(int argc, char **argv)
{

 int *ptr = NULL;
 int shmid = 0;
 key_t key = 0;
 key = 0x173686;

 shmid = shmget(key,sizeof(int),0666|IPC_CREAT);
 ptr = (int *) shmat(shmid,(void*)0,0);
 *ptr = clock();

 int maxNumChildren = 4;
 int concurrentChildren = 2;
 int maxTimeSeconds = 100;
 string fileName;

 int option_index = 0;
 char *user_name = NULL;
 while (( option_index = getopt(argc, argv, "n:s:t:h")) != -1){
   switch (option_index) {
     case 'n':
       maxNumChildren = atoi(optarg);
       break;
     case 's':
       concurrentChildren = atoi(optarg);
       break;
		 case 't':
	     maxTimeSeconds = atoi(optarg);
	     break;
		 case 'h':
	 		 cout<<"Usage: "<<argv[0]<<" [-n MaxNumber of children] [-s MaxNumber of concurrent processes] [-t MaxTime in seconds] InputFile"<<endl;
			 return 0;
     default:
      printf("Incorrect options.\n");
      return 1;
     } //end block for switch
   }  //end block for while

	fileName = argv[argc-1];

	cout<<"Max num childrens "<<maxNumChildren<<endl;
	cout<<"Max concurrent "<<concurrentChildren<<endl;
	cout<<"Max time "<<maxTimeSeconds<<endl;
	cout<<"Input file name "<<fileName<<endl;
	cout<<"Clock "<< *ptr <<endl;

	char *argvars[] = {"racecar", NULL };;
	cout << "Hello world" << endl;

	int counter = 0;
    pid_t pid = fork();

    if (pid == 0)
    {
	execvp("./program2",argvars);
        // child process
        int i = 0;
        for (; i < 5; ++i)
        {
            printf("child process: counter=%d\n", ++counter);
        }
    }
    else if (pid > 0)
    {
        // parent process
        int j = 0;
        for (; j < 5; ++j)
        {
            printf("parent process: counter=%d\n", ++counter);
        }
    }
    else
    {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }

    printf("--end of program--\n");

		shmdt((void *) ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;


}
