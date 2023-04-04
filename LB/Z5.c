#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    char name[20];
    printf("enter the name of file:\n");
    scanf("%s",&name);
    int fd=0;

    fd=creat(name,0777);

    if(fd==-1)
    {
        printf("there no space for file");
    }
    else
    {
        printf("File successfully created with %d fd",fd);
    }


}