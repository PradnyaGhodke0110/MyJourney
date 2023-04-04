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

    fd=open(Fname,O_RDWR | O_APPEND);

    if(fd==-1)
    {
        return -1;
    }
    
    printf("Enter tha data that you want write into the file:\n");
    scanf(" %[^'\n']s",Data);

    Length=strlen(Data);

    write(fd,Data,Length);
    

    return 0;
}
