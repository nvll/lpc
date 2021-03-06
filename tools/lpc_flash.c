#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	int x, in_fd, out_fd, sum, rd;
	int buf[1024]; // largest flash size is 32kb
	int size;

	if (argc != 3) {
		printf("usage: %s <.bin file> <device firmware.bin path>\n", argv[0]);
		exit(-1);
	}

	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);

	if(!(in_fd = open(argv[1], O_RDONLY))) {
		return -2;
	}

	if(!(out_fd = open(argv[2], O_WRONLY))) {
		return -3;
	}

	rd = read(in_fd, buf, sizeof(buf));

	if (!rd || rd < 32) {
		return -4;
	}

	for (x = 0; x < 7; x++)
		sum += buf[x];

	buf[7] = -sum;
	close(in_fd);

	write(out_fd, buf, rd);
	fsync(out_fd);
	close(out_fd);

	return 0;
}

