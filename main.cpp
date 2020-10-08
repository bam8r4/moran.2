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
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{

 key_t key = 13933;
 int shmid = shmget(key,sizeof(int),0666|IPC_CREAT);
 int *ptr = (int*) shmat(shmid,(void*)0,0);

 *ptr = 9;


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
	cout<<"Clock "<< ptr<<" "<<*ptr <<endl;

	char *argvars[] = {"racecar", NULL };;
	cout << "Hello world" << endl;

	int counter = 0;
	int curProcessCount = 0;
	int maxProcessCount = 0;
  pid_t pid;
	while(maxProcessCount <= maxNumChildren)
	{
		  while(curProcessCount >= concurrentChildren)
			{
				wait();

			}
			if(curProcessCount < concurrentChildren)
			{
				concurrentChildren += 1;
				maxProcessCount += 1;
				pid = fork();
			}

	    if (pid == 0)
	    {	  //Make child;
				  execvp("./program2",argvars);

	    }
	    else if (pid > 0)
	    {
	        // parent process
	    }
	    else
	    {
	        // fork failed
	        printf("fork() failed!\n");
	        return 1;
	    }
	}

    printf("--end of program--\n");

		shmdt((void *) ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;


}
