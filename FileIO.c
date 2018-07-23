/* * * * * * * * * * * * * * * * * * * * * * * * */
/* FileIO.c  * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "FileIO.h"

static unsigned char is_rgp_fname(char *str)
{
	assert(str);
	unsigned int i = 0;
	while(str[i] != 0)
	{
		if(str[i] == '.' && str[i+1] && str[i+1] == 'r' && str[i+2] && str[i+2] == 'g' && str[i+3] && str[i+3] == 'p' && !str[i+4])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

void clear_buff(char *buff, unsigned int length)
{
	assert(buff);

	unsigned int i;
	for(i = 0; i < length; i++)
	{
		buff[i] = 0;
	}
}

unsigned char isNum(char c)
{
	return c >= '0' && c <= '9';
}

GPSRectArr readFile(char *fname)
{
	assert(fname);
	GPSRectArr res = {0, (GPSRect *)NULL};
	GPSRect *curr = NULL;
	GPSRaw temp;
	char c = 0, buff[25] = {0};
	unsigned int counter = 0, counter2;
	unsigned char mode = 0;

	if(!is_rgp_fname(fname))
		return res; 

	FILE *file = fopen(fname, "r");

	while(c != EOF)
	{
		c = fgetc(file);
		if(c == 'G')
			counter++;
	}

	fseek(file, 0, SEEK_SET);

	res.array = malloc(sizeof(GPSRect)*counter);
	bytes_allocd += sizeof(GPSRect)*counter;
	res.length = counter;

	c = '0';
	counter = 0;
	while(c != EOF)
	{
		c = fgetc(file);
		switch(c)
		{
			case 'G':
			{
				fseek(file, 1, SEEK_CUR);
				fgets(buff, 8, file);
				temp.curr_time = atoi(buff);
				clear_buff(buff, 7);
				break;
			}

			case 'A':
			{
				fseek(file, 1, SEEK_CUR);
				fgets(buff, 3, file);
				temp.lat = atoi(buff);
				fseek(file, 1, SEEK_CUR);
				fgets(buff, 7, file);
				temp.lat_min = atoi(buff);
				clear_buff(buff, 6);
				break;
			}

			case 'O':
			{
				fseek(file, 1, SEEK_CUR);
				fgets(buff, 4, file);
				temp.lon = atoi(buff);
				fseek(file, 1, SEEK_CUR);
				fgets(buff, 7, file);
				temp.lon_min = atoi(buff);
				clear_buff(buff, 6);
				break;
			}

			case 'S':
			{
				c = '0';
				fseek(file, 1, SEEK_CUR);
				counter2 = 0;
				while(1)
				{
					c = fgetc(file);
					if(!isNum(c))
					{
						break;
					}
					buff[counter2++] = c;
				}
				temp.speed = atoi(buff);
				clear_buff(buff, 15);
				//printf("G:%d  A:%d %d  O:%d %d  S:%d\n", temp.curr_time, temp.lat, temp.lat_min, temp.lon, temp.lon_min, temp.speed);
				res.array[counter++] = raw2rect(temp);
				break;
			}

			default:
				break;
		}
	}

	fclose(file);
	return res;
}

#ifdef FILEIOTEST

int main()
{
	GPSRectArr t;
	t = readFile("test.rgp");
	deleteDataGPSRectArr(&t);
	printf("Bytes allocd = %d\nBytes Freed = %d\n\n", bytes_allocd, bytes_freed);
	return 0;
}

#endif
