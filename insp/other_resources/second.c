// C program to implement second site of FIFO. This reads first, then writes
#include <stdio.h>
#include <string.h>
#include <fcntl.h>          //O_RDONLY
#include <sys/stat.h>       //mkfifo
#include <sys/types.h>
#include <unistd.h>         //read, write, close

int main(int argc, char *argv[])
{
    int fd1;
    char *myfifo = "/tmp/myfifo";           //FIFO file pack
    mkfifo(myfifo, 0666);                   //creating the named file(FIFO)
    char arr1[80], arr2[80];
    while (1)
    {
        fd1 = open(myfifo, O_RDONLY);        // Open FIFO for Read only
        read(fd1, arr1, sizeof(arr1));        // Read from FIFO
        printf("First: %s\n", arr1);         // Print the read message
        close(fd1);

        fd1 = open(myfifo, O_WRONLY); // Open FIFO for write only
        fgets(arr2, 80, stdin);         //Take an input arr2ing from user
        write(fd1, arr2, strlen(arr2)+1);    //Write the input arr2ing on FIFO and close it
        close(fd1);
    }

}