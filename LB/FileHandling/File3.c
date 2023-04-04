#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

//O_RDONLY       OPEN FOR READING
//O_WRONLY       OPEN FOR WRITING
//O_RDWR         OPEN FOR READING AND WRITING

int OpenFile(char Name[])
{
    int fd=0;

    fd=open(Name,O_RDWR);

    return fd;
}
int main()
{
    char Fname[20];
    int fd=0;

    printf("enter the file name that you want to open:\n");
    scanf("%s",Fname);

    fd=OpenFile(Fname);

    if(fd==-1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File is Successfully opened with FD %d\n",fd);
    }
    return 0;


}
