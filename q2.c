#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
char buffer[1000000];
char buffer1[1000000];
char tempbuffer[1000000];
long long int size=1000000;

//FUNCTION TO REVERSE THE CASE OF CHARACTERS
void  reverse_case(long long int n)
{
	long long int i;
	for( i=0;i<n;i++)
	{
		if(buffer1[i]>=65 && buffer1[i]<=90)
			buffer1[i]=buffer1[i]+32;
		else if(buffer1[i]>=97 && buffer1[i]<=122)
			buffer1[i]=buffer1[i]-32;
		tempbuffer[n-i-1]=buffer1[i];
	}
}
// Function for Checking whether file contents have been reversed and case-inverted
long long int check(long long int F1,long long int F2)
{
	long long int size1=lseek(F1,0,SEEK_END);
	long long int size2=lseek(F2,0,SEEK_END);
	long long int count=size1;
	long long int j;
	if(size1!=size2)
	{
		return 1;
	}
	lseek(F1,0,SEEK_SET);
	while(size1>1000000)
	{

		read(F1,buffer,1000000);
		lseek(F1,size,SEEK_SET);

		lseek(F2,size1-1000000,SEEK_SET);
		read(F2,buffer1,1000000);

		reverse_case(1000000);

		for(j=0;j<1000000;j++)
		{
			if(tempbuffer[j]!=buffer[j])
			{
				return 1;
			}
		}

		size1=size1-1000000;
		size=size+1000000;

	}

	if(size1!=0)
	{

		lseek(F2,0,SEEK_SET);
		read(F2,buffer,size1);

		lseek(F1,-size1,SEEK_END);
		read(F1,buffer1,size1);

		reverse_case(size1);

		for(j=0;j<size1;j++)
		{
			if(tempbuffer[j]!=buffer[j])
				return 1;
		}
	}

	return 0;

}

int main(int argc, char * argv[])
{
	if(argc != 2){
	printf("Usage: ./a.out [filename]\n");
	return 0;
	}
	long long int F1,F2;

	struct stat check_d;
	struct stat file_status;
	struct stat symbolic_link;

	if(stat("Assignment",&check_d)==0)
	{
		write(1,"Checking whether the directory has been created:Yes\n",52);
	}
	else
	{
		write(1,"Checking whether the directory has been created: No\n",53);
	}
	if(stat("Assignment/reverse.txt",& file_status)==0)
	{
		write(1,"Checking whether the file has been created: Yes\n",48);
		symlink("Assignment/reverse.txt","symlink");
	}
	else
	{
		write(1,"Checking whether the file has been created: No\n",48);
	}
	if(stat("symlink",&symbolic_link)==0)
	{
		write(1,"Checking whether the symlink has been created: Yes\n",51);
	}
	else
	{
		write(1,"Checking whether the symlink has been created: No\n",51);
	}
		F1=open(argv[1],O_RDONLY);
		F2=open("Assignment/reverse.txt",O_RDONLY);
		if(check(F1,F2)==0)
		{
		write(1,"Checking whether file contents have been reversed and case-inverted: Yes\n",73);
		}
		else
		{
		write(1,"Checking whether file contents have been reversed and case-inverted: No\n",73);
		}
	write(1,"\n\n",2);


	if((file_status.st_mode & S_IRUSR)!=0)
	{
		write(1,"User has read permission on file: Yes\n",38);
	}
	else
	{
		write(1,"User has read permission on file: No\n",38);
	}
	if((file_status.st_mode & S_IWUSR)!=0)
	{
		write(1,"User has write permission on file: Yes\n",39);
	}
	else
	{
		write(1,"User has write permission on file: No\n",39);
	}
	if((file_status.st_mode & S_IXUSR)!=0)
	{
		write(1,"User has execute permission on file: Yes\n",41);
	}
	else
	{
		write(1,"User has execute permission on file: No\n",41);
	}

	write(1,"\n\n",2);


	if((file_status.st_mode & S_IRGRP)!=0)
	{
		write(1,"Group has read permission on file: Yes\n",39);
	}
	else
	{
		write(1,"Group has read permission on file: No\n",39);
	}
	if((file_status.st_mode & S_IWGRP)!=0)
	{
		write(1,"Group has write permission on file: Yes\n",40);
	}
	else
	{
		write(1,"Group has write permission on file: No\n",40);
	}
	if((file_status.st_mode & S_IXGRP)!=0)
	{
		write(1,"Group has execute permission on file: Yes\n",42);
	}
	else
	{
		write(1,"Group has execute permission on file: No\n",42);
	}


	write(1,"\n\n",2);

	if((file_status.st_mode & S_IROTH)!=0)
	{
		write(1,"Others has read permission on file: Yes\n",40);
	}
	else
	{
		write(1,"Others has read permission on file: No\n",40);
	}
	if((file_status.st_mode & S_IWOTH)!=0)
	{
		write(1,"Others has write permission on file: Yes\n",43);
	}
	else
	{
		write(1,"Others has write permission on file: No\n",43);
	}
	if((file_status.st_mode & S_IXOTH)!=0)
	{
		write(1,"Others has execute permission on file: Yes\n",42);
	}
	else
	{
		write(1,"Others has execute permission on file: No\n",42);
	}


	write(1,"\n\n",2);

	if((check_d.st_mode & S_IRUSR)!=0)
	{
		write(1,"User has read permission on directory: Yes\n",43);
	}
	else
	{
		write(1,"User has read permission on directory: No\n",43);
	}
	if((check_d.st_mode & S_IWUSR)!=0)
	{
		write(1,"User has write permission on directory: Yes\n",44);
	}
	else
	{
		write(1,"User has write permission on directory: No\n",44);
	}
	if((check_d.st_mode & S_IXUSR)!=0)
	{
		write(1,"User has execute permission on directory: Yes\n",45);
	}
	else
	{
		write(1,"User has execute permission on directory: No\n",45);
	}

	write(1,"\n\n",2);


	if((check_d.st_mode & S_IRGRP)!=0)
	{
		write(1,"Group has read permission on directory: Yes\n",43);
	}
	else
	{
		write(1,"Group has read permission on directory: No\n",43);
	}
	if((check_d.st_mode & S_IWGRP)!=0)
	{
		write(1,"Group has write permission on directory: Yes\n",44);
	}
	else
	{
		write(1,"Group has write permission on directory: No\n",44);
	}
	if((check_d.st_mode & S_IXGRP)!=0)
	{
		write(1,"Group has execute permission on directory: Yes\n",46);
	}
	else
	{
		write(1,"Group has execute permission on directory: No\n",46);
	}


	write(1,"\n\n",2);


	if((check_d.st_mode & S_IROTH)!=0)
	{
		write(1,"Others has read permission on directory: Yes\n",44);
	}
	else
	{
		write(1,"Others has read permission on directory: No\n",44);
	}
	if((check_d.st_mode & S_IWOTH)!=0)
	{
		write(1,"Others has write permission on directory: Yes\n",47);
	}
	else
	{
		write(1,"Others has write permission on directory: No\n",47);
	}
	if((check_d.st_mode & S_IXOTH)!=0)
	{
		write(1,"Others has execute permission on directory: Yes\n",47);
	}
	else
	{
		write(1,"Others has execute permission on directory: No\n",47);
	}
	close(F1);
	close(F2);
}
