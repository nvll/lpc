#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int x, fd, sum, chksum, rd;
    int buf[8];

    if (argc < 2) {
        printf("usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open (argv[1], O_RDWR);
    rd = read(fd, buf, 4 * 8);

    for (x = 0; x < 8; x++)
        sum += buf[x];

    if (sum == 0) {
        printf("chksum is correct!\n");
        close(fd);
        exit(0);
    } else {
        chksum = -(sum - buf[7]);
    }

    lseek(fd, 4 * 7, SEEK_SET);
    write(fd, &chksum, 4);
    close(fd);

    printf("chksum calculated as 0x%x and updated\n", chksum);
    return 0;
}

