/*
PROGRAM TO PRACTICE MULTIPLE WAYS TO SQUARE A NUMBER USING FLOAT AND DIFFRENT OPERATORS
Psudo Code:
1)Define a variable "number","answer" as a float data type.
2)Print an output of the number multiplied by itself.

ASSUMPTIONS:
1)The assigned number is in the range of float data type.
*/
#include<stdio.h>
int main()
{
	float number,answer;
	number = 10;
	answer = number * number;

	printf("The square of the number %f is %f",number, answer);
//squaring the number by adding it with itself itself number of times.
//NOTE:- This method is not accurate with non integers or {{negative integers.(FIXXEDDDD!!!!!!!!!)}}

	int number1,range,temporaryans;
	number1 = -11;
	temporaryans =number1;
	range = 0;
	/*converting negative assigned number to positive one for the while loop by assigning the value of assigned number to an unsigned int data type
		and then assigning its value back to the assigned number.*/
	/*if (number1 < 0)
	{
		unsigned int value;
		value = number1;
		number1 = value;
	};*/
	// In case of negative numbers, The while loop keeps adding the negative values to the temporary answer. As a result, the result has a negative sign. This is fixed later.
	while (range <= (number-1))
	{
		temporaryans=temporaryans+number1;
		range++;
		
		
	};
	// There is a funcion to take the absolute value LOL....
	int removeminus;
	removeminus = abs(temporaryans);
	printf("\r\nThe square of the number %d by adding it with itself is %d", number1, removeminus);
}
