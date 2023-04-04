#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char Fname[20];
    int fd=0,Length=0;
    char Data[100];

    printf("enter the file name that you want to open:\n");
    scanf("%s",Fname);

    fd=open(Fname,O_RDWR);

    if(fd==-1)
    {
        return -1;
    }

    //read(kuthun,kashat,kiti);
    read(fd,Data,13);

    printf("Data From file is %s",Data);
    
    return 0;
}
