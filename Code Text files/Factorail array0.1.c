#include<stdio.h>
#include<string.h>
//#include <stdlib.h>
//#include<math.h>
//#include"D:\Programs\C libraries\Anjaneya_Library\Anjaneya_Library\Anjaneya.h"
#pragma warning(disable : 4996)			//to avoid fopen_s

char array_factorial(char input_array[100]);
int decrement1(char number_array[100]);


int main()
{
	char input_array[102] = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	array_factorial(input_array);
}

char array_factorial(char input_array[100])
{
	int total_digits=strlen(input_array);
	int answer_array[5000];
	int number_array1[101];
	int number_array2[101];
	int carry;
	int counter;


	printf("Array has %d elements", total_digits);
	if (total_digits > 100)
	{
		printf("\nThe input is larger than 100 digits.\nPlease Make sure it is not.\n");
		exit(1);
	}
	number_array1[100] = total_digits;										//100th position of the array will contain the total digits the array holds.
	if ((total_digits == 1) && (input_array[0] =='0'))						//0 factorial =1
	{
		printf("\n0!=1");
		return 1;
	}
	for (counter = 0; counter < total_digits; counter++)				//Making sure only digits are there in the input array
	{
		if ((input_array[counter] < 48) || (input_array[counter] > 57))
		{
			printf("\nA non digit has been passed in the input array.");
			printf("\nThe non digit in the array is '%c' at the %d position of the array",number_array1[counter],counter);
			exit(1);
		}

	}
	for (counter = 0; counter < total_digits; counter++)	//Converting numbers string into int array
	{
		number_array1[counter] = input_array[counter] - 48;
	}
	//for (counter = 0; counter < total_digits; counter++)		//Making sure start numbers are not 0
	//{
	//	if (number_array1[array_shift_value] == 0)
	//	{
	//		array_shift_value++;
	//	}
	//	else if (number_array1[array_shift_value] != 0)
	//	{
	//		break;
	//	}
	//}
	//carry = array_shift_value;
	//for (counter = 0; counter < carry; counter++)
	//{
	//	number_array1[counter] = number_array1[array_shift_value];
	//	array_shift_value++;
	//}

	//printf("\nNew numbers:\n");

	//for (counter = 0; counter < total_digits-carry; counter++)
	//{
	//	printf("[%d]", number_array1[counter]);
	//}
	printf("\n[");																	//Calculating Factorial
	for (counter = 0; counter < total_digits; counter++)
	{
		printf("%d", number_array1[counter]);
	}
	printf("]\n");
	decrement1(number_array1, &total_digits);

	printf("\nAfter Decrement\n[");																	//Calculating Factorial
	for (counter = 0; counter < total_digits; counter++)
	{
		printf("%d", number_array1[counter]);
	}
	printf("]\n");
}
int decrement1(int number_array[101])				//Decrementing the number by 1 (int array)
{
	int reverse_counter=number_array[100]-1;
	int zero_counter=0;
	while (1)
	{
		if (number_array[reverse_counter] != 0)
		{
			if ((zero_counter == number_array[100] - 1) && (number_array[0] == 1)&&((number_array[100] -1)!=0))
			{
				number_array[100] = number_array[100] - 1;
				for (zero_counter = 0; zero_counter < number_array[100]; zero_counter++)
				{
					number_array[zero_counter] = 9;
				}
				break;
			}
			else
			{
				number_array[reverse_counter] = number_array[reverse_counter] - 1;
				reverse_counter++;
				if (zero_counter != 0)
				{
					for (reverse_counter; reverse_counter < number_array[100]; reverse_counter++)
					{
						number_array[reverse_counter] = 9;
					}
				}
				break;
			}
		}
		else if (number_array[reverse_counter] == 0)
		{
			zero_counter++;
			reverse_counter--;
		}

	}	

}