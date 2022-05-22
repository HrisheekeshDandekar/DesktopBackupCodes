//#include<stdio.h>
//int main()
//{
//
///*--------------Dynamically allocating 2d array-----------------------*/
//	char rows = 3;
//	char columns = 4;
//	char** two_D_Arr;
//	two_D_Arr = (char**)malloc(rows * sizeof(char*));
//	for (int i = 0; i < rows; i++)
//	{
//		two_D_Arr[i] = (char*)malloc(columns * sizeof(char));
//	}
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			two_D_Arr[i][j] = j;
//		}
//	}
//
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			printf("[ %d ]", two_D_Arr[i][j]);
//		}
//		printf("\n");
//	}
//}