/*
Q4.Write a program that implements all file operations(open/creat/write/read/lseek/close).
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    
    int fd1, fd2, len;
    char read_buff[100];

    fd1 = creat("lunix2.txt", 777);         //Creating a new file
    
    fd2 = open("lunix1.txt", O_RDONLY, 777);            //Opening a existing file in read only mode

    len = read(fd2, read_buff, 100);            //Reading the data from fd2 file and storing it in read_buff
   
    //printf("Seeing data stored in len = %d\n\n", len);            //checking whether data is storing in read_buff or not
   
    printf("Showing the data in stored in read_buff = \n%s\n\n", read_buff);

    len = write(fd1, read_buff, len);           //Writing the data in newly created file--> lunix.txt

    printf("Performing lseek operation:\n\n");

    lseek(fd2, 0, SEEK_SET);            //Performing the lseek operation reading the data from 0 means from 1st word charcter by character.
    read(fd2, read_buff, 50);
    printf("The data after seeking is: \n\n%s\n", read_buff);

    close(fd2);         //Closing the file
    close(fd1);

    return 0;
}
