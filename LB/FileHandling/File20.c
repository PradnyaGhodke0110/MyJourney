#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    
    
    int fdSource = 0,fdDest = 0, length = 0, ret = 0;
    char Data[100];
    
    fdSource = open(argv[1], O_RDONLY);
    if (fdSource == -1)
    {
        printf("Unable to open\n");
        return -1;
    }
    
    
    fdDest=creat(argv[2],0777);

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

    printf("Data Successfullly copiedd");
    
    return 0;
}

//At the time of execution we should give output like this
//File12(exename)=argv[0]  Marvellous.txt=argv[1] Demo.txt=argv[2]
