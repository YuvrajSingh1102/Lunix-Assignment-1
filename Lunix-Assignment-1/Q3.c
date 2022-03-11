/*
Q3.Write program that returns “ls -l ” kind of structure of information from an existing file or
opend file.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char input[50];

    printf("Enter the information or file name using extension: ");         //Taking input as a file name
    scanf("%s", input);

    printf("Executing ls -l....\n");

    execl("/bin/ls", "ls", "-l", input, 0);            //Performing operation ls -l on the file which user has given as a input.
    printf("I execute is program");


return 0;
}