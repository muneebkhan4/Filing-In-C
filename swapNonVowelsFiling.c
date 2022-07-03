#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>


int main(int argc, char* argv[])
{
	char data[1000];                  // making space to get data from file...


	printf("Please enter file_name.txt: \n");
	FILE* file_read;
	FILE* file_write;
	file_read = fopen(argv[1], "r");

	if (file_read == NULL)
	{
		printf("Erro in opeing file.\n");
	}

	else
	{
		char z = 'z';             // help in reading file
		int index = 0;            // index for data...
		while ((z = fgetc(file_read)) != EOF)
		{
			data[index] = z;                                // reading file
			index++;
		}
		data[index]='\0';
		fclose(file_read);

		int i = 0;
		int k = 0;
		while (i < index)
		{
			int j = 0;
			while (data[i] != ' ' && i < index)        // separating words by space
			{
				j++;
				i++;
			}
			k = i - j;
			j = i - 1;
			while (k < j)       // processing the word
			{
				int check = 0;
				while (data[k] == 'a' || data[k] == 'e' || data[k] == 'i' || data[k] == 'o' || data[k] == 'u')
				{
					k++;
				}
				while (data[j] == 'a' || data[j] == 'e' || data[j] == 'i' || data[j] == 'o' || data[j] == 'u')
				{
					j--;
				}
				char temp = data[j];           // swaping those pair which are not vowel...
				data[j] = data[k];
				data[k] = temp;
				k++;
				j--;
			}

			i++;

		}
		
		file_write = fopen(argv[1], "w");
		int sec_index = 0;
		while (index > 0)
		{
			
			fprintf(file_write, "%c", data[sec_index]);             // writing file
			sec_index++;
			index--;
		}
	}
	
        printf("\n%s",data);
	printf("\nThe file has been updated\n.");

	return 0;
}
