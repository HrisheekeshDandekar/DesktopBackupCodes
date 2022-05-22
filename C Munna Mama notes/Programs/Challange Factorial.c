/*
PROGRAM TO FIND THE FACTORIAL OF AN INTEGER.
Psudo code:
1)Define a variable "number","range"as an integer, "answer" long double.
2)let range decrement itself by till 1 starting from the value of number.
3)Let asnwer be number * range. Keep multiplying till range is 1
4)print answer.
ASSUMPTIONS:
1)The input number is an integer and not a fraction.
3)The input number is a positive number.
2)The result of theoperation can be stored in long double data type.
*/
#include<stdio.h>
int main()
{
	int number, range;
	long double answer;
	number = 0;
	answer = number;
	if (number == 0)
	{
		printf("Factorial of 0 is 1");
	}
	else if (answer > -1)
	{
		range = number - 1;
		while (range > 0)
		{
			answer = answer * range;
			range--;
		}
		printf("The factorial of the number %d is %Lf", number, answer);


	}
	else
	{
		range = number + 1;


		while (range < 0)
		{
			answer = answer * range;
			range++;

		}
		printf("The factorial of the number %d is %Lf", number, answer);

	}