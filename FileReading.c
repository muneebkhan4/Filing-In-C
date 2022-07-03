#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char*argv[]) 
{
	printf("Please enter file_name.txt and sub string respectively: ");
	
	FILE* file;
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("\n\nError opeing file.\n");          // file not exist error...
	}

	else                           // other wise search sub string in file and count them
	{
		char* y = malloc(30);             // dynamic memory
		char z;                            // read from file char by char
		int i = 0;
		int count = 0;                      // for counting
		while ((z = fgetc(file)) != EOF)      // to read the whole file
		{
			if (z == ' ')                 // get words from file separated by space
			{
				y[i] = '\0';
				
				if (strcmp(y, argv[2]) == 0)   // cmpare with subString
				{
					count++;               // increment count
				}
				i = 0;
				free(y);                      // free the dynamic memeory
				y = malloc(30);               // againg get space for new word
			}
			else
			{
				y[i] = z;
				i++;
			}
		}
		y[i-1] = '\0';
		
		if (strcmp(y, argv[2]) == 0)
		{
			count++;                           // to count the last word from file
		}
		i = 0;
		free(y);                                // free dynamic memory

		printf("\n\nNumber of occurence of sub String is: %d", count);
		fclose(file);                //close file
	}


	return 0;
}


