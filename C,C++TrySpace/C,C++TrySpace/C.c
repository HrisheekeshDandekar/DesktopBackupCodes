//#pragma warning(disable : 4996)																				
//#include<stdio.h>
//int sets_n_details();
//int check_intersection(int math_size, int science_size, int* math, int* science);
//int display_union(int math_size, int science_size, int* math, int* science);
//int show_diffrance(int math_size, int science_size, int* math, int* science);
//
//int main()
//{
//	sets_n_details();
//}
//int sets_n_details()
//{
//	int students_in_math,students_in_science;
//	printf("Enter the number of students in Maths section : ");
//	scanf("%d", &students_in_math);
//	printf("Enter the number of students in Science section : ");
//	scanf("%d", &students_in_science);
//
//	int* maths;
//	maths = (int*)malloc(students_in_math * sizeof(int) + 10);		//Dynamically Created Array for math roll nos
//	int* science;
//	science = (int*)malloc(students_in_science * sizeof(int) + 10);		//Dynamically Created Array	for sci roll nos
//
//	printf("Enter Roll Numbers saperated by space for students in Maths :");
//
//	for (int i = 0; i < students_in_math; i++)
//	{
//		scanf("%d", &maths[i]);
//	}
//
//	printf("Enter Roll Numbers saperated by space for students in Science :");
//
//	for (int i = 0; i < students_in_science; i++)
//	{
//		scanf("%d", &science[i]);
//	}
//
//	check_intersection(students_in_math, students_in_science, maths, science);
//	display_union(students_in_math, students_in_science, maths, science);
//	show_diffrance(students_in_math, students_in_science, maths, science);
//
//	return 0;
//}
//
//int check_intersection(int math_size, int science_size, int* math, int* science)
//{
//	int intersection_found = 0;
//	printf("\nStudents in both domains are (Intersection) : ");
//	for (int i = 0; i < math_size; i++)
//	{
//		for (int j = 0; j < science_size; j++)
//		{
//			if (math[i] == science[j])
//			{
//				printf(" [%d] ", math[i]);
//				intersection_found = 1;
//			}
//		}
//	}
//	if (intersection_found == 0)
//	{
//		printf("Intersection Not Found!\n");
//	}
//}
//
//int display_union(int math_size, int science_size, int* math, int* science)
//{
//	int unique = 1;
//	printf("\nUnion is : ");
//	for (int i = 0; i < science_size; i++)
//	{
//		printf(" [%d] ", science[i]);
//	}
//	for (int i = 0; i < math_size; i++)
//	{
//		for (int j = 0; j < science_size; j++)
//		{
//			if (math[i] == science[j])
//			{
//				unique = 0;
//			}
//		}
//		if (unique == 1)
//		{
//			printf(" [%d] ", math[i]);
//		}
//	}
//}
//
//int show_diffrance(int math_size, int science_size, int* math, int* science)
//{
//	int unique = 1;
//	printf("\nStudents Unique to Maths : ");
//	for (int i = 0; i < math_size; i++)
//	{
//		for (int j = 0; j < science_size; j++)
//		{
//			if (math[i] == science[j])
//			{
//				unique = 0;
//			}
//		}
//		if (unique == 1)
//		{
//			printf(" [%d] ", math[i]);
//		}
//		unique = 1;
//	}
//	int unique_sci = 1;
//	printf("\nStudents Unique to Science : ");
//	for (int i = 0; i < science_size; i++)
//	{
//		for (int j = 0; j < math_size; j++)
//		{
//			if (science[i] == math[j])
//			{
//				unique_sci = 0;
//			}
//		}
//		if (unique_sci == 1)
//		{
//			printf(" [%d] ", science[i]);
//		}
//		unique_sci = 1;
//	}
//	
//}