/*
* ----------{	Program to Calculate Students grades	}----------
* INPUTS:
* 1. number of students
* 2. number of subjects
* 3. marks for each subject
*
* By - 221018_Hrisheekesh Dandekar
*/

#pragma warning(disable : 4996)	//Use this command if VS 2019 is being used																			
#include<iostream>
#include<stdio.h>

using namespace std;

class Student
{
public:
	float avrage = 0;
	float* subject_marks;
	int subject_count;
	char name[50];
	int *roll_number;

	Student(int total_subjects,int total_students)		//Parameterized Constructor
	{
		subject_marks = (float*)malloc(total_subjects * sizeof(float) + 1);	//Making an array to store marks for each subject
		subject_count = total_subjects;
		roll_number = (int*)malloc(total_students * sizeof(int) + 10);
	}

	void get_details(int p)
	{
		int x = p - 1;
		int check_inputs = 0;
		do
		{
			getchar();			//To clear previous 
			printf("\nEnter Student's name: \n");
			scanf("%[^\n]s", &name);

			int roll_check = 0;
			while (roll_check == 0)
			{
				printf("\nEnter Student's roll number : ");
				scanf("%d", &roll_number[x]);

				if ((roll_number[x] < 221001) || roll_number[x] > 221071)
				{
					printf("\n\nRoll Number must be in range 221001 - 221071\n");
				}
				else
				{
					roll_check = 1;
				}
			}

			for (int i = 0; i < subject_count; i++)
			{

			enter_marks_again:
				int subject_no = i + 1;
				printf("\nEnter Subject %d's Marks: ", subject_no);
				scanf("%f", &subject_marks[i]);
				if ((subject_marks[i] < 0) || (subject_marks[i] > 100))			//Making sure entries are in range 0-100
				{
					printf("\nPlease make sure your inputs are between 0 and 100 and try again..\n");
					goto enter_marks_again;
				}
			}
		} while (check_inputs == 1);
		for (int i = 0; i < subject_count; i++)
		{
			avrage += subject_marks[i];
		}
		avrage = avrage / subject_count;
	}
	void show_details(int i)
	{
		printf("\nStudent [ %s ]\n", name);

		printf("Roll no: %d\n",roll_number[i-1] );

		printf("\nAvrage Score : %f\n", avrage);
		if (avrage >= 80)
		{
			printf("Grade : \033[0;33mA\033[0m\n");
		}
		else if (avrage >= 60)
		{
			printf("Grade : \033[0;33mB\033[0m\n");

		}
		else if (avrage >= 40)
		{
			printf("Grade : \033[0;33mC\033[0m\n");

		}
		else
		{
			printf("Grade : \033[0;33mD\033[0m\n");
		}
		avrage = 0;
	}

};

int main()
{
	int students = 0;
	int total_subjects = 0;
	while (students < 1)
	{
		cout << "Enter the number of students : ";
		scanf("%d", &students);
		if (students < 1)
		{
			cout << "Total number of students cannot be less than 1" << endl;
		}
	}

	while (total_subjects < 1)
	{
		cout << "Enter the number of subjects : ";
		scanf("%d", &total_subjects);
		if (total_subjects < 1)
		{
			cout << "Total number of subjects cannot be less than 1" << endl;
		}
	}

	Student s1(total_subjects,students);

	for (int i = 1; i < students + 1; i++)
	{
		printf("\n\033[0;32m====================|\033[0;36m Student %d \033[0;32m|====================\033[0m\n", i);
		s1.get_details(i);
		s1.show_details(i);
	}
}

