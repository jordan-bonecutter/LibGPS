#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <assert.h>
#include <pthread.h>
#define CFUL(x) (x == '1' ? 1 : 0)

char print_buff[0xFFF];
char _buff[999520];

int open_port(char *portname)
{
	assert(portname);
	int fd;

	fd = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd < 0)
	{
		perror("Unable to open port");
		exit(1);
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
	}

	struct termios options;
	tcgetattr(fd, &options);
	cfsetispeed(&options, B115200);
	cfsetospeed(&options, B115200);
	options.c_cflag |= (CLOCAL | CREAD);
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	tcsetattr(fd, TCSANOW, &options);

	return fd;
}
void read_t(int fd)
{
	while(1)
	{
		read(fd, print_buff, 255);
		printf("%s", print_buff);
		memset(print_buff, 0, 256);
	}
}

int main(int argc, char **argv)
{
	int fd = open_port(argv[1]), count = 0, n = 0;
	memset(_buff, 0, 11520);
	memset(print_buff, 0, 0xFFF);
	FILE *file = fopen("test.rgp", "w");

	while(1)
	{
		read(fd, print_buff, 0xFFF-1);
		if(CFUL(print_buff[0]) && CFUL(print_buff[1]) && CFUL(print_buff[2]) && CFUL(print_buff[3])
		&& CFUL(print_buff[4]) && CFUL(print_buff[5]) && CFUL(print_buff[6]) && CFUL(print_buff[7]))
		{
			printf("%s\n", print_buff);
			while(print_buff[count+8] != 0)
			{
				_buff[count] = print_buff[count+8];
				count++;
			}
			printf("Got start signal...\n");
			printf("%s\n", _buff);
			break;
		}
	}

	while(count < 995190)
	{
		count += read(fd, _buff + count, 999519);
		if(n%60 == 0)
		{
			printf("%s\n", _buff + count - 7);
		}
		n++;
	}

	count = 300;
	while(_buff[++count] != 'G');

	printf("Filled buffer...\n");
	fputs(_buff + count, file);
	fclose(file);

	close(fd);
}
