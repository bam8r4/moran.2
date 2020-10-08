#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{

 int maxNumChildren = 4;
 int concurrentChildren = 2;
 int maxTimeSeconds = 100;

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
	 		 printf("Printing usage:\n");
			 return 0;
     default:
      printf("Incorrect options.\n");
      return 1;
     } //end block for switch
   }  //end block for while

	cout<<"Max num childrens "<<maxNumChildren<<endl;
	cout<<"Max concurrent "<<concurrentChildren<<endl;
	cout<<"Max time "<<maxTimeSeconds<<endl;

	char *argv[] = {"racecar", NULL };;
	cout << "Hello world" << endl;

	int counter = 0;
    pid_t pid = fork();

    if (pid == 0)
    {
	execvp("./program2",argv);
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

    return 0;


}
