// C program to implement one site of FIFO. This writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //O_RDONLY
#include <sys/stat.h> //mkfifo
#include <sys/types.h>
#include <unistd.h> //read, write, close

int main(int argc, char *argv[])
{
    int fd;
    char *myfifo = "/tmp/myfifo"; //FIFO file pack
    mkfifo(myfifo, 0666);           //creating the named file(FIFO)
    char arr1[80], arr2[80];
    while (1)
    {
        fd = open(myfifo, O_WRONLY); // Open FIFO for write only
        fgets(arr2, 80, stdin);         //Take an input arr2ing from user
        write(fd, arr2, strlen(arr2)+1);    //Write the input arr2ing on FIFO and close it
        close(fd);
        fd = open(myfifo, O_RDONLY);        // Open FIFO for Read only
        read(fd, arr1, sizeof(arr1));        // Read from FIFO
        printf("Second: %s\n", arr1);         // Print the read message
        close(fd);
    }

}