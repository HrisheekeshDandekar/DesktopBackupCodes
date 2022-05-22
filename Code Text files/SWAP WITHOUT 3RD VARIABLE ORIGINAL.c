/**********************************************
PROGRAM TO SWAP THE DATA BETWEEN 2 VARIABLES WITHOUT TAKING A 3rd VARIABLE

Psudo Code:
1)Ask the user for the method by which one wants to swap the data
2)Specify the range of the integers which can be assigned for swapping in each method
3)Show the swapped data


Limitations(for now):
1)One can only input integers as entering a float value will cause the program to malfunction.
2)One cannot exceed the specified limits of the data types used.
3)In int main(), Other variables have been used to check for the validity of input (idk how to get a value error without checking the validity by storing the input 
  in a variable with higher range of storage) but the swapping method true to its word does not use more than two variables.
3)No exeption Handeling for events when characters are entered as an input.  
4)Exeption Handeling falis for SwappWithDiff method when input exceeds range of int data type, same case for DiffWithBinary when limit exceeds the range of int data type
5)SWAP WITH BINARY DOES NOT WORK FOR NUMBERS WITH OPPOSITE SIGNS (easily fixable if I can take another variable to rectify the sign.)

***********************************************/








#include<stdio.h>

void SwapWithDiff(int x, int y);
void SwapWithBinary(short int x,short int y);

void main()
{   

	int Choice, RangeLimitCheck,x,y; // Variables for checking input


	//Asking for the method to be used for swap
	wrongchoice:
	printf("Choose the method you would like to swap the data between two variables");
	printf("\n");
	printf("Enter 1 to swap with diffrence method (range -2147483648 to 2147483647)");
	printf("\n");
	printf("Enter 2 to swap with binary method (range -32768 to 32767)");
	printf("\n");
	scanf_s("%d", &Choice);

	//Checking if the choice input is valid
	if (Choice == 1)
	{

	rangeerror1:  //Checking range for the input of SWAP WITH DIFFERENCE method
		printf("Enter number1: ");
		printf("\n");
		scanf_s("%d", &RangeLimitCheck);

		if ( (RangeLimitCheck > 2147483647) || (RangeLimitCheck< -2147483647) )
		{
			printf("Please enter an integer in the range -2147483648 to 2147483646");
			goto rangeerror1;
		}
		else
		{
			x = RangeLimitCheck;
			RangeLimitCheck = 0;
		}
		rangeerror2:
		printf("Enter number2: ");
		printf("\n");
		scanf_s("%d", &RangeLimitCheck);

		if ((RangeLimitCheck > 2147483647) || (RangeLimitCheck < -2147483647))
		{
			printf("Please enter an integer in the range -2147483648 to 2147483646");
			goto rangeerror2;
		}
		else
		{
			y = RangeLimitCheck;
			RangeLimitCheck = 0;
		}

		SwapWithDiff(x, y);
	}


	else if (Choice == 2)
	{
		wrongrange1:   //Checking the range for the input for SWAP WITH BINARY method
		printf("Enter number1: ");
		printf("\n");
		scanf_s("%d", &RangeLimitCheck);

		if ( (RangeLimitCheck < -32768) || (RangeLimitCheck > 32767) )
		{
			printf("The value has to be between the specified range of -32768 to 32767");
			printf("\n");
			goto wrongrange1;
		}

		if((RangeLimitCheck >= -32768) && (RangeLimitCheck <= 32767))
		{
			x = RangeLimitCheck;
			RangeLimitCheck = 0;
		}

		wrongrange2:
		printf("Enter number2: ");
		printf("\n");
		scanf_s("%d", &RangeLimitCheck);

		if ((RangeLimitCheck < -32768) || (RangeLimitCheck > 32767))
		{
			printf("The value has to be between the specified range of -32768 to 32767");
			printf("\n");
			goto wrongrange2;
		}

		if ((RangeLimitCheck >= -32768) && (RangeLimitCheck <= 32767))
		{
			y = RangeLimitCheck;
			RangeLimitCheck = 0;
		}
		if ( (x < 0) && (y > (-1)) )
		{
			x = x*(-1);



		}
		
		SwapWithBinary(x, y);	

	}
	else
	{
		printf("Wrong input. Please Enter 1 or 2");
		printf("\n");
		goto wrongchoice;
	}
}

//Source for swap with difference method

void SwapWithDiff(int x, int y)
{
	x = x + y;
	y = x - y;
	x = x - y;
	printf("number1 after swap = %d \nnumber2 after swap = %d", x, y);
	printf("\n");

}


//Source for swap with difference method
/*
   Each bit is compared with the same position bit of the other variable.
   If the bits are same, the next bit is checked
   If the bits are not same, both of them are swapped
   The bits are checked by bitwise "or" (|) operator by making each other bit 1 
   The value in a bit is reversed by "xor" (^) operator if it is found to be diffrent from the same position bit of the ther variable.
   Print statements are commented for each bits to help look for faulty bit checking blocks in future
*/


void SwapWithBinary(short int x,short int y)
{

	
	if ( (x | 65534) == (y | 65534) )
	{
		printf("The 1st bit is the same.");
		printf("\n");
	}
	else
	{
		x = x ^ 1;
		y = y ^ 1;
	}
	if ( (x | 65533) == (y | 65533) )
	{
		printf("The 2nd bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 2;
		y = y ^ 2;
	}
	if ( ( x | 65531 ) == ( y | 65531 ) )
	{
		printf("The 3rd bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 4;
		y = y ^ 4;
	}
	if ((x | 65527) == (y | 65527))
	{
		printf("The 4th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 8;
		y = y ^ 8;
	}
	if ((x | 65519) == (y | 65519))
	{
		printf("The 5th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 16;
		y = y ^ 16;
	}
	if ((x | 65503) == (y | 65503))
	{
		printf("The 6th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 32;
		y = y ^ 32;
	}
	if ((x | 65471) == (y | 65471))
	{
		printf("The 7th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 64;
		y = y ^ 64;
	}
	if ((x | 65407) == (y | 65407))
	{
		printf("The 8th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 128;
		y = y ^ 128;
	}
	if ((x | 65279) == (y | 65279))
	{
		printf("The 9th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 256;
		y = y ^ 256;
	}
	if ((x | 65023) == (y | 65023))
	{
		printf("The 10th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 512;
		y = y ^ 512;
	}
	if ((x | 64511) == (y | 64511))
	{
		printf("The 11th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 1024;
		y = y ^ 1024;
	}
	if ((x | 63487) == (y | 63487))
	{
		printf("The 12th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 2048;
		y = y ^ 2048;
	}
	if ((x | 61439) == (y | 61439))
	{
		printf("The 13th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 4096;
		y = y ^ 4096;
	}
	if ((x | 57343) == (y | 57343))
	{
		printf("The 14th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 8192;
		y = y ^ 8192;
	}
	if ((x | 49151) == (y | 49151))
	{
		printf("The 15th bit is same  ");
		printf("\n");
	}
	else
	{
		x = x ^ 16384;
		y = y ^ 16384;
	}
	if ((x | 1015807) == (y | 1015807))
	{
		printf("The 16th bit is same  "); // This bit is supposed to decide the sign of the number
		printf("\n");                 

	}
	else
	{
		x = x ^ 32768;
		y = y ^ 32768;
	}

	printf("Number1 after swap = %hd \nNumber2 after swap = %hi", x, y);
	printf("\n");


	
}


