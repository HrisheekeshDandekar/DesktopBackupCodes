#pragma warning(disable : 4996)																				
#include<iostream>
#include<stdio.h>
#define TOTAL_STUDENTS 10
using namespace std;

////class Student
////{
////public:
////	char name[50];
////	int age;
////	float C_marks;
////	float Cpp_marks;
////	float Java_marks;
////
////	void get_details()
////	{
////		printf("\nEnter your name: \n");
////		scanf("%[^\n]s", &name);
////		printf("\nEnter your age : \n");
////		scanf("%d", &age);
////		printf("\nEnter your C maks : \n");
////		scanf("%f", &C_marks);
////		printf("\nEnter your C++ marks: \n");
////		scanf("%f", &Cpp_marks);
////		printf("\nEnter your Java marks: \n");
////		scanf("%f", &Java_marks);
////	}
////	void show_details()																					
////	{																		
////		printf("\nName \033[0;32m----------------[\033[0m%s\033[0;32m]--------------------\033[0m\n\n", name);
////		printf("\nAge \033[0;32m-----------------[\033[0m%d\033[0;32m]--------------------\033[0m\n\n", age);
////		printf("\nC marks \033[0;32m-------------[\033[0m%f\033[0;32m]--------------------\033[0m\n\n", C_marks);
////		printf("\nC++ marks \033[0;32m-----------[\033[0m%f\033[0;32m]--------------------\033[0m\n\n", Cpp_marks);
////		printf("\nJava marks \033[0;32m----------[\033[0m%f\033[0;32m]--------------------\033[0m\n\n", Java_marks);
////	}																											
////};		
////int main()														
////{																	
////	Student s1[TOTAL_STUDENTS];									
////	for (int i = 0; i < TOTAL_STUDENTS; i++)					
////	{														
////		printf("\n\033[0;32m------------------------------------\033[0m\n");
////		s1[i].get_details();								
////		s1[i].show_details();								
////		printf("\n\033[0;32m------------------------------------\033[0m\n");
////	}
//////}
////int main()
////{
////	int m = 4;
////	m = ++m + ++m;
////	cout << m;
////}
//#include<iostream>
//using namespace std;
//
//class Grade {
//public:
//    int NumOfStud, tot_subjects;
//    float m1, m2, m3;
//    float* total = (float*)malloc(NumOfStud * sizeof(float) + 10);
//    float* avg=(float*)malloc(NumOfStud * sizeof(float) + 10);
//    float* subject_marks = (float*)malloc(tot_subjects * sizeof(float) + 10);
//    /*Grade()
//    {
//
//    }*/
//    void get_details()
//    {
//        cout << "Enter the number of students: ";
//        cin >> NumOfStud;
//        cout << "Enter the number of subjects: ";
//        cin >> tot_subjects;
//        for (int i = 0; i < NumOfStud; i++)
//        {
//            cout << "Student " << i + 1 << endl;
//            for (int j = 0; j < tot_subjects; j++)
//            {
//                cout << "Enter marks for Subject " << j+1 << " : ";
//                cin >> subject_marks[j];
//            }
//            for (int j = 0; j < tot_subjects; j++)
//            {
//                total[i] = total[i] + subject_marks[j];
//            }
//            avg[i] = total[i] / tot_subjects;
//        }
//
//    }
//    void show_details()
//    {
//        cout << "************" << endl;
//        cout << "RESULTS OF STUDENTS" << endl;
//        cout << "************" << endl;
//        for (int i = 1; i <= NumOfStud; i++)
//        {
//            cout << "Student " << i << endl;
//            cout << "Your total marks are " << total[i-1] << endl;
//
//            cout << "Your average marks are " << avg[i-1] << endl;
//            if (avg[i-1] >= 80)
//            {
//                cout << "You have secured A grade" << endl;
//            }
//            else if (avg[i - 1] >= 60)
//            {
//                cout << "You have secured B grade" << endl;
//            }
//            else if (avg[i - 1] >=40)
//            {
//                cout << "You have secured C grade" << endl;
//            }
//            else {
//                cout << "You have secured D grade" << endl;
//            }
//            cout << "************" << endl;
//        }
//
//    }
//
//};
//
//int main()
//{
//    Grade g1;
//    g1.get_details();
//    g1.show_details();
//    return 0;
//}
int display(int* marks)
{
	for (int i = 0; i < 5; i++)
	{
		cout << *marks;
	}
	return 0;
}
int main()
{
	int marks[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		display(&marks[i]);
	}
}