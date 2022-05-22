2) Program to find if the given number is even or odd.

ERROR CODE::::::
/*
PROGRAM TO CHECK IF THE ASSIGNED NUMBER IS EVEN OR ODD.
Psudo Code:
1)Define a variable as "number","check"
2)Divide the number by 2 and store the remaimder in "check"
3)If cehck has value 1 or -1, print that the assigned number is odd.
4)If the value of check is 0, print the assigned nunmber is even.

Assumptions:
The assigned number is an Integer.
*/

#include<stdio.h>
int main()
{
	int number, check;
	number = -6546212;
	check = number%2;

	if (check == 1||-1)
	{
		printf("The assigned number %d is an odd integer.", number);

     }
	else
	{
		printf("The assigned number %d is an even integer", number);
	}

	return 0;
	

}





Working code::::
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

#include<stdio.h>
int main()
{
	//Defining variables "number","check" as integer data types
	int number, check;
	number = -65469211;	

	//Checking if the number is even or odd by comparing the remainder of the division by two with the number.
	if (number % 2==1)
	{
		printf("The assigned positive number %d is an odd integer.", number);

     }
	else if(number % 2 == -1)
	{
		printf("The assigned negative integer %d is an odd integer ", number);
	}
	else
	{
		printf("The assigned number %d is an even integer", number);
	}

	return 0;
	
}