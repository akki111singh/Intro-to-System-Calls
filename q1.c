#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include<errno.h>
#include<sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
char buffer[1000000];
char tempbuffer[1000000];

//function for reversing the case and array
void  reverse_case(long long int n)
{
	long long int i;
	for(i=0;i<n;i++)
	{
		if(buffer[i]>=65 && buffer[i]<=90)
			buffer[i]=buffer[i]+32;
		else if(buffer[i]>=97 && buffer[i]<=122)
			buffer[i]=buffer[i]-32;

		tempbuffer[n-i-1]=buffer[i];

	}
}

int main(int argc, char * argv[])
{
	if(argc != 2){
		printf("Usage: ./a.out [filename]\n");
		return 0;
	}

	long long int F1,F2;
	long long int i=0;
	char c;

	F1=open(argv[1],O_RDONLY);    


	if(F1<=0)
	{
		printf("No input file exits");
	}
	mkdir("Assignment",0700);  //700 gives read write and execute to new directory Assignment

	F2=open("Assignment/reverse.txt",O_RDWR |O_CREAT,0700);


	long long int size=lseek(F1,0,SEEK_END);  //find the total no. of characters to copy using lseek
	long long int size2=size;

		while(size2>1000000)
		{
			lseek(F1,size2-1000000,SEEK_SET);    //move pointer to copy next 1MB


			long long int r=read(F1,buffer,1000000);
			reverse_case(1000000);
			long long int w=write(F2,tempbuffer,1000000);

			if(w<=0)
			{
				printf("Failed to write in file");
				exit(1);
			}
			size2=size2-1000000;
		}

		if(size2!=0)
		{
			lseek(F1,0,SEEK_SET);
			read(F1,buffer,size2);
			reverse_case(size2);
			write(F2,tempbuffer,size2);
		}

	close(F1);                                   //close the files F1 and F2
	close(F2);
	return 0;
}
