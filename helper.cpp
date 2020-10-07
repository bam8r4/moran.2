#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


using namespace std;

int main(int argc,char *argv[])
{

	string potPal = argv[0];
	int length = 0;
	int flag = 0;

	cout<<"Yo I am the new process!"<<endl;
	
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
	

  return 0;
}
