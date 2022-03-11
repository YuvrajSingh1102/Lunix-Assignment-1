/*
Q2.Write a program that demonstrates repositioning of file offset using SEEK_SET, SEEK_END
and SEEK_END.
*/

#include<stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
	
int main()
{
	int fd1, fd2, fd3;
	int len=0;
	
	
	char write_buff[] = "This is Writing data to file.txt file\n";
		
	fd1 = open("file1.txt", O_CREAT | O_RDWR, 0666);            //Writing to file1.txt 
	len = write(fd1 , write_buff, sizeof(write_buff));
	printf("In File descriptor fd1 : %d\n", fd1);
    	printf("Checking the data is written in len or not: %d\n",len);
	
	
	lseek(fd1, 0, SEEK_SET);		//set cursor to beginning
	
	
	char read_buff[len];
	
	read(fd1, read_buff, len);          //Reading character by character from the file1.txt
	printf("\nContents in file are: %s",read_buff);
    	printf("\n");
	close(fd1);

	int length=0;
	char buffer[]="This file contains data to perform concept of lseek and it's flags: SEEK_SET, SEEK_CUR, SEEK_END";
	int head=0;

	
	head = lseek(fd1, 0, SEEK_CUR);
	printf("\nCurrent position of file is: %d\n",head);
	
	
	fd2 = open("file1.txt", O_RDWR, 0666);
	lseek(fd2, 0, SEEK_END);
	
	
	length = write(fd2 , buffer, sizeof(buffer));
	printf("\nFile descriptor returned by fd2 is: %d and data written length is: %d\n",fd1,length);
	
	
	lseek(fd2, len, SEEK_SET);
	char buffer1[length];
	
	
	read(fd2, buffer1, length);
	printf("\nContents are: %s\n",buffer1);
	
	
	close(fd2);
	
	
	return 0;
}
