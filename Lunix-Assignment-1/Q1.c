/*
1.Write a program using file operations that demonstrates copying of data from input file and write
into output file, untill reaches end of file data.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int fd, fd1, len;
    char data_buff[100];

    fd = open("lunix.txt", O_RDONLY, 0777);         //Opening file 1 in read mode only
    fd1 = open("lunix1.txt", O_CREAT | O_RDWR, 0777);           // Opening file 2 in read and write mode

    //Reading from the file 1 lunix.txt
    len = read(fd, data_buff, 100);

    //printf("Total=%d\n", len);

    //Writing to file 2 lunix1.txt
    write(fd1, data_buff, len);


    close(fd); 
    close(fd1);

    return 0;
}