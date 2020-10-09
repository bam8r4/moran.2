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
#include <fstream>


using namespace std;

int main(int argc,char *argv[])
{

	key_t key = 13933;
  int shmid = shmget(key,sizeof(int),0666|IPC_CREAT);
  int *ptr = (int*) shmat(shmid,(void*)0,0);

	string potPal = argv[0];
	int length = 0;
	int flag = 0;

	//cout<<"Here are some more values: "<<intptr<<" "<<*intptr<<endl;
	length = potPal.length();
	cout<<length<<endl;

	for(int i=0;i < length ;i++)
	{
        	if(potPal[i] != potPal[length-i-1]){
            		flag = 1;
            		break;
		}
  	}

	if(flag == 0)
	{
		cout<<potPal<<" is a palindrome"<<endl;
	}
	else
	{
		cout<<potPal<<" is not a palindrome"<<endl;
	}


  exit(0);
}
