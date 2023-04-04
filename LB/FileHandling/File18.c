#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char Fname1[20];
    char Fname2[20];
    
    int fdSource = 0,fdDest = 0, length = 0, ret = 0;
    char Data[100];
    printf("Enter the file name that you want to open:\n");
    scanf("%s", Fname1);

    fdSource = open(Fname1, O_RDONLY);
    if (fdSource == -1)
    {
        printf("Unable to open\n");
        return -1;
    }
    
    printf("Enter the file name that you want to create:\n");
    scanf("%s",Fname2);

    fdDest=creat(Fname2,0777);

    if(fdDest==-1)
    {
       printf("Unable to create new file\n");
        return -1;
    }

    while ((length = read(fdSource, Data, sizeof(Data))) != 0)
    {
        write(fdDest, Data, length);
        // length--;
    }
    close(fdSource);
    close(fdDest);
    
    return 0;
}
