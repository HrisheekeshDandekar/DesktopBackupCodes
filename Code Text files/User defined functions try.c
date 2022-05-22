#include<stdio.h>
long double Factorial(int number);
long double SquareByMultiplication(float inputnumber);
int SquareByAddition(int number1);
int EvenOdd(int number1);
void PrimeNotPrime(int number1);
void AdditionInt(long double,long double);











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

// Preparing a user defined funcion where a factorial is calculated
long double Factorial(int number)
{
	int range;
	long double answer;

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
}

/*
PROGRAM TO PRACTICE MULTIPLE WAYS TO SQUARE A NUMBER USING FLOAT AND DIFFRENT OPERATORS
Psudo Code:
1)Define a variable "number","answer" as a float data type.
2)Print an output of the number multiplied by itself.

ASSUMPTIONS:
1)The assigned number, answer  is in the range of float data type.
*/

//Defining UDF



long double SquareByMultiplication(float inputnumber)
{

	long double output;
	output = inputnumber * inputnumber;
	printf("\r\nThe square of number %f by multiplication is %Lf",inputnumber,output);

}

int SquareByAddition(int number1)
{
	//squaring the number by adding it with itself itself number of times.
//NOTE:- This method is not accurate with non integers or {{negative integers.(FIXXEDDDD!!!!!!!!!)}}

	int counter, temporaryans;
	temporaryans =0;
	counter = 0;
	/*converting negative assigned number to positive one for the while loop 
		and then assigning its value back to the assigned number.*/
		if (number1 < 0)
		{
			number1 = number1 * (-1);
		};
		// In case of negative numbers, The while loop keeps adding the negative values to the temporary answer. As a result, the result has a negative sign. Hence its first converted into a positive number
	while (counter <= (number1-1))
	{
		temporaryans = temporaryans + number1;
		counter++;


	};
	printf("\r\nThe square of the number %d by adding it with itself is %d", number1, temporaryans);




/*
PROGRAM TO CHECK IF THE ASSIGNED NUMBER IS EVEN OR ODD.
Psudo Code:
1)Define a variable as "number","check"
2)Divide the number by 2 and store the remaimder in "check"
3)If cehck has value 1 or -1, print that the assigned number is odd.
4)If the value of check is 0, print the assigned nunmber is even.

Assumptions:
The assigned number is an Integer.
2)The integer entered is not larger than 2147483647 and not lesser then -2147483647
*/


int EvenOdd(int number1)
{
	//Defining variables "number","check" as integer data types
	int number, check;
	number = number1;

	//Checking if the number is even or odd by comparing the remainder of the division by two with the number.
	if (number % 2 == 1)
	{
		printf("The assigned positive number %d is an odd integer.", number);

	}
	else if (number % 2 == -1)
	{
		printf("The assigned negative integer %d is an odd integer ", number);
	}
	else
	{
		printf("The assigned number %d is an even integer", number);
	}

	return 0;

}


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
// stdlib.h library is requitred for exit() command WRONG return(0 ) does the trick
#include<stdlib.h>


void PrimeNotPrime(int number1)
{
	//Declaring variables "number","range" as integers and assigning value 2 to range and any other integer in the range -2147483647 to +2147483647 to number.
	int number, range;
	number = number1;
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


//This program uses two variables and gives an output of its addition
/*
Define two variables as number 1 and number2.
divide number 1 by number 2

*/

void AdditionInt(long double number3, long double number4)
{
	long double number1, number2;
	number1 = number3;
	number2 = number4;
	long double answer;
	answer = number1 + number2;
	printf("The addition of the two numbers is %Lf", answer);
}

