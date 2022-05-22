3)Prime check UNFINISHED
/*
PROGRAM TO CHECK IF THE ASSIGNED NUMBER IS PRIME OR NOT
PSUDO CODE:
1)Define a variable as "number".
2)If the number is smaller than 2, the given nnumber is not a prime number.
2)Divide the number by each number smaller than it and larger than 1.
3)If it is divisible by any of the numbers stated in (2), state that the number is a composite number.
4)Else state that its a prime number

ASSUMPTIONS:
1)The number entered is an integer.
2)The integer entered is not larger than 2147483647 and not lesser then -2147483647

*/
#include<stdio.h>
int main()
{
	int number,range,primecheck;
	number =2;
	range = 4;
	if (number < 2)
	{
		printf("The assigned number %d is not a Prime number", number);
	}
	else
	{
		while (range <= number)
		{
			if (number % range == 0)
			{
				primecheck = 1;
				break;
			}
			range++;
		}
	
	}
	printf(primecheck);
}

2)PRIME NUMBER FINISHED::
/*
PROGRAM TO CHECK IF THE ASSIGNED NUMBER IS PRIME OR NOT
PSUDO CODE:
1)Define a variable as "number".
2)If the number is smaller than 2, the given number is not a prime number.
2)Divide the number by each number smaller than it and larger than 1.
3)If it is divisible by any of the numbers stated in (2), state that the number is a composite number.
4)Else state that its a prime number

ASSUMPTIONS:
1)The number entered is an integer.
2)The integer entered is not larger than 2147483647 and not lesser then -2147483647

*/
#include<stdio.h>
// stdlib.h library is requitred for exit() command
#include<stdlib.h>
int main()
{
//Declaring variables "number","range" as integers and assigning value 2 to range and any other integer in the range -2147483647 to +2147483647 to number.
	int number, range;
	number = 9465442;
	range = 2;
//Checking if the number is less than 2. If yes, It is not a prime number
	if (number < 2)
	{
		printf("The assigned number %d is not a Prime number", number);
	}
	else
	{
		//Dividing every number smaller than the assigned number in the range 2 to (number-1). 
		while (range < number)
		{
			if (number % range == 0)
			{
				printf("The assigned number %d is not a prime number", number);
				// If the assigned number is divisible by any other number than itself and 1, it is not prime and thus the program must not try its divisibility with other numbers. 
				exit(0);
			}
			else
			{
				//After checking if the number is divisible by the current value of range, range is incrimented by 2 to prepare for the next tumber to divide the asigned number with.
				range++;
			}
			//If the assigned number is not divisible ny any other number but itself and 1, we can safely say it is a prime number.
		}
		printf("The assigned number %d is a prime number",number);
	}
	return 0;
}



le edits
/*
PROGRAM TO CHECK IF THE ASSIGNED NUMBER IS PRIME OR NOT
PSUDO CODE:
1)Define a variable as "number".
2)If the number is smaller than 2, the given number is not a prime number.
2)Divide the number by each number smaller than it and larger than 1.
3)If it is divisible by any of the numbers stated in (2), state that the number is a composite number.
4)Else state that its a prime number

ASSUMPTIONS:
1)The number entered is an integer.
2)The integer entered is not larger than 2147483647 and not lesser then -2147483647

*/
#include<stdio.h>
// stdlib.h library is requitred for exit() command
#include<stdlib.h>
int main()
{
	//Declaring variables "number","range" as integers and assigning value 2 to range and any other integer in the range -2147483647 to +2147483647 to number.
	int number, range;
	number = 9465442;
	range = 2;
	//Checking if the number is less than 2. If yes, It is not a prime number
	if (number < 2)
	{
		printf("The assigned number %d is not a Prime number", number);
	}
	else
	{
		//Dividing every number smaller than the assigned number in the range 2 to (number-1). 
		while (range < number)
		{
			if (number % range == 0)
			{
				printf("The assigned number %d is not a prime number", number);
				// If the assigned number is divisible by any other number than itself and 1, it is not prime and thus the program must not try its divisibility with other numbers. 
				//RETURN 0 IS BETTER 
				return 0;
			}
			else
			{
				//After checking if the number is divisible by the current value of range, range is incrimented by 2 to prepare for the next tumber to divide the asigned number with.
				range++;
			}
			//If the assigned number is not divisible ny any other number but itself and 1, we can safely say it is a prime number.
		}
		printf("The assigned number %d is a prime number", number);
	}
	return 0;
}