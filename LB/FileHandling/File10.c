 #include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char Fname[20];
    int fd=0,ret=0;
    char Data[100];

    printf("enter the file name that you want to open:\n");
    scanf("%s",Fname);

    fd=open(Fname,O_RDWR);

    if(fd==-1)
    {
        return -1;
    }

    //read(kuthun,kashat,kiti);
    ret=read(fd,Data,13);

    printf("Data From file is \n");
    write(1,Data,ret);// 1 indicate you have to display data on terminal
    
    close(fd);
    
    return 0;
}