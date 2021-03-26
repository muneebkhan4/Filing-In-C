#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>


int main()
{

                                                 // file name is data.txt
	char input='x';
	int ignore = 0;
	printf("Press 'a' to add new student.\nPress 'b' to read students record.\nPress 'c' delete student record from file.\nOr any other key to exit.\n");

	ignore = scanf("%c", &input);      // input


	if (input == 'a')              // if a is pressed
	{
		char name[50];
		char rollNo[15];             // name email and roll number
		char email[50];
		printf("Enter name: ");
		ignore = scanf("%s", name);

		printf("Enter roll number: ");
		ignore = scanf("%s", rollNo);

		printf("Enter email: ");
		ignore = scanf("%s", email);

		printf("%s\n%s\n%s\nrecord has been added.\n", name, rollNo,email);

		FILE* file;

		file = fopen("data.txt", "a");                         // add new student

		ignore = fprintf(file, "\n%s", name);
		ignore = fprintf(file, "\n%s", rollNo);
		ignore = fprintf(file, "\n%s", email);

	    fclose(file);
	
	}
	else if (input == 'b')                   // if b is pressed
	{
		int secInput=-1;
		printf("Press 0 to view your record.\nPress 1 to view 1st record.\nPress 2 to view 2nd record.\n");
		ignore=scanf("%d", &secInput);
		
		char name[50];
		char rollNo[15];
		char email[50];

		char Waste[50];
		
		FILE* file;

		file = fopen("data.txt", "r");
		for (int i = 0; i < secInput; i++)                     // geting desired student
		{
			ignore = fscanf(file, "%[^\n]\n", Waste);
			ignore = fscanf(file, "%[^\n]\n", Waste);
			ignore = fscanf(file, "%[^\n]\n", Waste);
		}
		ignore = fscanf(file, "%[^\n]\n", name);
		ignore = fscanf(file, "%[^\n]\n", rollNo);
		ignore = fscanf(file, "%[^\n]\n", email);
		
		fclose(file);

		printf("Name: %s\n", name);
		printf("Roll nunber: %s\n", rollNo);                      // printing information of that student.
		printf("email: %s\n", email);
	}

	else if (input == 'c')                // if c is pressed
	{
		int secInput = -1;
		printf("Press 0 to delete your record.\nPress 1 to delete 1st record.\nPress 2 to delete 2nd record.\n");
		ignore = scanf("%d", &secInput);
		char name1[50];
		char rollNo1[15];
		char email1[50];

		char name2[50];
		char rollNo2[15];
		char email2[50];

		char name3[50];                     // name roll number and email of all three studentss...
		char rollNo3[15];
		char email3[50];

		FILE* file;

		file = fopen("data.txt", "r");
		
		ignore = fscanf(file, "%[^\n]\n", name1);
		ignore = fscanf(file, "%[^\n]\n", rollNo1);
		ignore = fscanf(file, "%[^\n]\n", email1);
		
		ignore = fscanf(file, "%[^\n]\n", name2);
		ignore = fscanf(file, "%[^\n]\n", rollNo2);                   // reading data of all three students
		ignore = fscanf(file, "%[^\n]\n", email2);

		ignore = fscanf(file, "%[^\n]\n", name3);
		ignore = fscanf(file, "%[^\n]\n", rollNo3);
		ignore = fscanf(file, "%[^\n]\n", email3);


		fclose(file);

		file = fopen("data.txt", "w");
		if (secInput != 0)
		{
			ignore = fprintf(file, "%s", name1);
			ignore = fprintf(file, "\n%s", rollNo1);
			ignore = fprintf(file, "\n%s\n", email1);
		}
		if (secInput != 1)
		{
			ignore = fprintf(file, "%s", name2);                 // writing back the data expect the one who is deleted...
			ignore = fprintf(file, "\n%s", rollNo2);
			ignore = fprintf(file, "\n%s\n", email2);
		}
		if (secInput != 2)
		{
			ignore = fprintf(file, "%s", name3);
			ignore = fprintf(file, "\n%s", rollNo3);
			ignore = fprintf(file, "\n%s", email3);
		}
		if(secInput<=2 && secInput>-1)
		{
			printf("deleted succesffully.\n");
		}
		else
		{
			printf("delete Unsuccessful.\n");
		}

		fclose(file);
	}

	return 0;
}
