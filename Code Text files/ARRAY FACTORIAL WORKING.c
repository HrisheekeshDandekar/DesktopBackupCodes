#include<stdio.h>
#include<string.h>
//#include <stdlib.h>
//#include<math.h>
//#include"D:\Programs\C libraries\Anjaneya_Library\Anjaneya_Library\Anjaneya.h"
#pragma warning(disable : 4996)			//to avoid fopen_s

char array_factorial(char input_array[102]);
int decrement1(char number_array[102]);
//int multiply(int answer_array[5002], int number_array[102]);
int add_arrays(int answer_array[5002], int temp_array[5002]);
int multiply_and_update(int answer_array[5002], int number_array[102]);


int main()
{
	char input_array[102] = "6000";
	array_factorial(input_array);
}

char array_factorial(char input_array[102])
{
	int initial_total_digits=strlen(input_array);
	int answer_array[5002];
	int number_array[102];
	int counter;

	if (initial_total_digits > 100)
	{
		printf("\nThe input is larger than 100 digits.\nPlease Make sure it is not.\n");
		exit(1);
	}
	number_array[100] = initial_total_digits;										//100th position of the array will contain the total digits the array holds.
	if ((initial_total_digits == 1) && (input_array[0] =='0'))						//0 factorial =1
	{
		printf("\n0!=1");
		return 1;
	}
	for (counter = 0; counter < initial_total_digits; counter++)				//Making sure only digits are there in the input array
	{
		if ((input_array[counter] < 48) || (input_array[counter] > 57))
		{
			printf("\nA non digit has been passed in the input array.");
			printf("\nThe non digit in the array is '%c' at the %d position of the array",number_array[counter],counter);
			exit(1);
		}

	}
	for (counter = 0; counter < initial_total_digits; counter++)	//Converting numbers string into int array
	{
		number_array[counter] = input_array[counter] - 48;
	}
	//for (counter = 0; counter < number_array[100]; counter++)		//Making sure start numbers are not 0
	//{
	//	if (number_array[array_shift_value] == 0)
	//	{
	//		array_shift_value++;
	//	}
	//	else if (number_array[array_shift_value] != 0)
	//	{
	//		break;
	//	}
	//}
	//carry = array_shift_value;
	//for (counter = 0; counter < carry; counter++)
	//{
	//	number_array[counter] = number_array[array_shift_value];
	//	array_shift_value++;
	//}

	//printf("\nNew numbers:\n");

	//for (counter = 0; counter < number_array[100]-carry; counter++)
	//{
	//	printf("[%d]", number_array[counter]);
	//}



	//printf("\n[");																	//Displaying number
	//for (counter = 0; counter < number_array[100]; counter++)
	//{
	//	printf("%d", number_array[counter]);
	//}
	//printf("]\n");

	/*
		printf("\nAfter Decrement\n[");																
	for (counter = 0; counter < number_array[100]; counter++)
	{
		printf("%d", number_array/2[counter]);
	}
	printf("]\n");

	*/


									
							//Checks Done, satrt of factorial calculation\\

	for (counter = 0; counter < initial_total_digits; counter++)			//Copying number into asnwer array
	{
		answer_array[counter] = number_array[counter];
	}
	answer_array[5000] = number_array[100];								//Answer length same as number for now
	while ((number_array[0] != 1) || (number_array[100] != 1))			//Loop Runs till the number is not 1
	{
		decrement1(number_array);
		multiply_and_update(answer_array, number_array);				
	}


	printf( "\nAnswer Array :" );
	for (counter = 0; counter < answer_array[5000]; counter++)
	{
		printf("%d", answer_array[counter]);
	}

	char answer_string[5002];												//Converting int array to a string for writing in a text file
	for (counter = 0; counter < answer_array[5000]; counter++)
	{
		answer_string[counter] = answer_array[counter] + 48;
	}
	answer_string[answer_array[5000]] = '\0';
	printf("\n%s", answer_string);
	FILE* file = fopen("C:\\Users\\pc\\Desktop\\Factorial_result.txt", "w");

	int results = fputs(answer_string, file);
	if (results == EOF) 
	{
		printf("\nCould not writeeeee");
	}
	fclose(file);
}		

int decrement1(int number_array[102])				//Decrementing the number by 1 (int array)
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


int multiply_and_update(int answer_array[5002], int number_array[102])
{


	int temp_answer_array[5002];	//To store the answer of multiplication of ans array with each digit of num array then finally replacing asnwer array with it
	temp_answer_array[5000] = 0;
	int reverse_array[5002];
	reverse_array[5000] = 0;
	int temp_answer;
	int carry=0;
	int counter_num,counter_ans,counter_rev=0,counter_carry;

	for (counter_num= (number_array[100]-1); counter_num >= 0; counter_num--)								//Looping through all the digits in the num array from units place
	{
		carry = 0;
		counter_rev = 0;
		for (counter_ans = answer_array[5000] - 1; counter_ans >= 0; counter_ans--)				//Looping through all the digits in the ans array from units place, multiplying it the current num array digit
		{
			temp_answer = (number_array[counter_num] * answer_array[counter_ans]) + carry;
			reverse_array[counter_rev] = temp_answer % 10;
			counter_rev++;
			reverse_array[5000] = reverse_array[5000] + 1;
			carry = temp_answer / 10;
			if ((counter_ans == 0) && (carry != 0))												//Adding the carry if all the ans array numbers have been multiplied with 					
			{
				reverse_array[reverse_array[5000]] = carry;
				reverse_array[5000] = reverse_array[5000] + 1;
			}
		}
		for (counter_carry = 0; counter_carry < (reverse_array[5000] / 2); counter_carry++)							//Reversing the reverse array
		{
			temp_answer = reverse_array[counter_carry];
			reverse_array[counter_carry] = reverse_array[reverse_array[5000] - counter_carry - 1];
			reverse_array[reverse_array[5000] - counter_carry - 1] = temp_answer;
		}
		for (counter_carry = 0; counter_carry < (number_array[100] - 1 - counter_num); counter_carry++)					//Adding 0's to the end of ans depending on the location of the num_array digit
		{
			reverse_array[reverse_array[5000]] = 0;
			reverse_array[5000] = reverse_array[5000] + 1;
		}
		add_arrays(temp_answer_array, reverse_array);
		reverse_array[5000] = 0;
	}
	answer_array[5000] = temp_answer_array[5000];
	for (counter_ans = 0; counter_ans < answer_array[5000]; counter_ans++)
	{
		answer_array[counter_ans] = temp_answer_array[counter_ans];
	}

}

int add_arrays(int answer_array[5002], int temp_array[5002])
{
	int carry = 0;
	int temp, largest_length, counter_smaller_array, counter_larger_array;
	if (answer_array[5000] >= temp_array[5000])
	{
		counter_larger_array = answer_array[5000] - 1;
		largest_length = answer_array[5000];
		for (counter_smaller_array = temp_array[5000] - 1; counter_smaller_array >= 0; counter_smaller_array--)
		{
			temp = answer_array[counter_larger_array] + temp_array[counter_smaller_array];
			temp = temp + carry;
			answer_array[counter_larger_array] = temp % 10;
			carry = temp / 10;
			counter_larger_array--;
		}
		if (carry != 0)
		{
			for (counter_larger_array = (answer_array[5000] - temp_array[5000] - 1); counter_larger_array >= 0; counter_larger_array--)
			{
				temp = answer_array[counter_larger_array] + carry;
				answer_array[counter_larger_array] = temp % 10;
				carry = temp / 10;
			}
			if (carry != 0)
			{
				for (counter_smaller_array = answer_array[5000]; counter_smaller_array > 0; counter_smaller_array--)
				{
					answer_array[counter_smaller_array] = answer_array[counter_smaller_array - 1];
				}
				answer_array[0] = carry;
				answer_array[5000] = answer_array[5000] + 1;
			}
		}
	}
	else
	{
		counter_larger_array = temp_array[5000] - 1;
		largest_length = temp_array[5000];
		for (counter_smaller_array = answer_array[5000] - 1; counter_smaller_array >= 0; counter_smaller_array--)
		{
			temp = temp_array[counter_larger_array] + answer_array[counter_smaller_array];
			temp = temp + carry;
			temp_array[counter_larger_array] = temp % 10;
			carry = temp / 10;
			counter_larger_array--;
		}
		if (carry != 0)
		{
			for (counter_larger_array = (temp_array[5000] - answer_array[5000] - 1); counter_larger_array >= 0; counter_larger_array--)
			{
				temp = temp_array[counter_larger_array] + carry;
				temp_array[counter_larger_array] = temp % 10;
				carry = temp / 10;
			}
			if (carry != 0)
			{
				for (counter_smaller_array = temp_array[5000]; counter_smaller_array > 0; counter_smaller_array--)
				{
					temp_array[counter_smaller_array] = temp_array[counter_smaller_array - 1];
				}
				temp_array[0] = carry;
				temp_array[5000] = temp_array[5000] + 1;
			}
		}
		answer_array[5000] = temp_array[5000];
		for (counter_larger_array = 0; counter_larger_array < answer_array[5000]; counter_larger_array++)
		{
			answer_array[counter_larger_array] = temp_array[counter_larger_array];
		}
	}

}