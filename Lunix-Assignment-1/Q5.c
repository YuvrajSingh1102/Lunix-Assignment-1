/*
Q5.Write a program that creates a file with a 4K bytes free space. (Such files are called files with
holes.)
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char file[] = "NULL";

int main()
{
     int fd1 = creat("Q5.txt", 777);			//create file name of Q5.c
     
     if(fd1 < 0)
     {
            perror("Creation error");
	    exit(1);
     }
     
     if(lseek(fd1,4094,SEEK_SET) < 0)			//Creating space of 4KB free by shifting fd to 4094
     {
	    perror("Positioning error");
            exit(3);
     }
     
     if(write(fd1,file,sizeof(file)) < 0)		//writing NULL value to file
     {
	    perror("Writing error");
            exit(2);
     }
     
     close(fd1);
     return 0;
} 
