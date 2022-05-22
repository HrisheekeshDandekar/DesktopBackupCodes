#include<stdio.h>
#include<string.h>
#include"C:\Users\pc\source\repos\Console_menu_1.0\display_console_menu.h"
#pragma warning(disable : 4996)			

					//FUNCTIONS

int never_give_up(int error_no);			//Quotes
int border_art(int border_type);			//Border function

		/*Assignment Fucntions for '=' operator*/
int c_int(long double user_value, int expression_code);
unsigned int c_unsigned_int(long double user_value, int expression_code);
short c_short(long double user_value, int expression_code);
unsigned short c_unsigned_short(long double user_value, int expression_code);
long c_long(long double user_value, int expression_code);
unsigned long c_unsigned_long(long double user_value, int expression_code);
char c_char(long double user_value, int expression_code);

					/*Scanf for common data types*/
int int_scanf();


int main()
{
	int trya;
	trya = int_scanf();
	printf("%d", trya);
	long double test_compatibility=300.3;
	char a = c_char(test_compatibility,6);
	border_art(1);
	border_art(5);
}

									/*Setting limits for scanf data type wise*/
		

									//   scanf for INTEGER values
int int_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	int final_return = 0;
	char temp;
	size_t length = 0;
	int index = 0;
	int flag = 0;
	int all_okay_flag;
	while (pre_lim_test == 0) {
		all_okay_flag = 0;
		length = 0;
		flag = 0;
		pre_lim_test = 0;

		printf("\nPlease enter a number -2147483647 to 2147483647:");
		fgets(userinput, 63, stdin);
		length = strlen(userinput);

		if (length < 0 || length > 63) {				//making sure the input does not exceed the array limits
			printf("\nInput Should be in the range of 0-63 characters\n");
			all_okay_flag = 1;
			continue;
		}

		length--;

		for (index = 0; index < length; ++index)						//testing if any character other than the numbers , '.', '-' are entered			
		{
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47))
			{
				all_okay_flag = 1;
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			printf("\nInvalid character. Please Enter inputs in from of digits or '.'\n");
			continue;
		}

		if (sscanf(userinput, "%lf", &pre_lim_test) != 1)
		{
			all_okay_flag = 1;
			printf("\nCould not assign the input. Please Make sure it is not empty and try again\n");
			continue;
		}

		if (pre_lim_test < -2147483647 || pre_lim_test > 2147483647)
		{
			all_okay_flag = 1;
			printf("\nThe number you are trying to input exceeds the data range int variable can hold\n");
			//continue;
		}
		if (all_okay_flag == 0)
		{
			final_return = pre_lim_test;
			if (final_return == 0)
			{
				return final_return;
				break;
			}
			return(final_return);
			break;
		}
		else
		{
			pre_lim_test = 0;
		}
	}
}

						//   scanf for UNSIGNED INTEGER values

unsigned int uint_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	unsigned int final_return = 0;
	char temp;
	size_t length = 0;
	int index = 0;
	int flag = 0;
	int all_okay_flag;
	while (pre_lim_test == 0) {
		all_okay_flag = 0;
		length = 0;
		flag = 0;
		pre_lim_test = 0;

		printf("\nPlease enter a number 0 to 4294967295:");
		fgets(userinput, 63, stdin);
		length = strlen(userinput);

		if (length < 0 || length > 63) {				//making sure the input does not exceed the array limits
			printf("\nInput Should be in the range of 0-63 characters\n");
			all_okay_flag = 1;
			continue;
		}

		length--;

		for (index = 0; index < length; ++index)						//testing if any character other than the numbers , '.', '-' are entered			
		{
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47))
			{
				all_okay_flag = 1;
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			printf("\nInvalid character. Please Enter inputs in from of digits or '.'\n");
			continue;
		}

		if (sscanf(userinput, "%lf", &pre_lim_test) != 1)
		{
			all_okay_flag = 1;
			printf("\nCould not assign the input. Please Make sure it is not empty and try again\n");
			continue;
		}

		if (pre_lim_test < 0 || pre_lim_test > 4294967295)
		{
			all_okay_flag = 1;
			printf("\nThe number you are trying to input exceeds the data range unsigned int variable can hold\n");
			//continue;
		}
		if (all_okay_flag == 0)
		{
			final_return = pre_lim_test;
			if (final_return == 0)
			{
				return final_return;
				break;
			}
			return(final_return);
			break;
		}
		else
		{
			pre_lim_test = 0;
		}
	}
}



											//Motivational Quotes for error codes
									/*In the battle of stamina, the mind decides the victor*/

int never_give_up(int error_no)
{
	if (error_no < 0)
	{
		error_no = error_no * (-1);
	}
	error_no = error_no % 10;
	printf("\033[4;96m");
	switch (error_no)
	{
	case 1:
		printf("\n\tIt's not that I'm so smart, it's just that I stay with problems longer.\n\t- Albert Einstein\n");
		break;
	case 2:
		printf("\n\tMany of life’s failures are people who did not realize how close they were to success when they gave up\n");
		break;
	case 3:
		printf("\n\tCourage doesn’t always roar. \n\tSometimes courage is the quiet voice at the end of the day saying ‘I will try again tomorrow.\n");
		break;
	case 4:
		printf("\n\tSuccess is no accident. \n\tIt is hard work, perseverance, learning, studying, sacrifice and most of all, love of what you are doing or learning to do.\n");
		break;
	case 5:
		printf("\n\tIn the realm of ideas everything depends on enthusiasm… in the real world all rests on perseverance.\n");
		break;
	case 6:
		printf("\n\tCourage is not having the strength to go on\n\tIt is going on when you don't have the strength.\n");
		break;
	case 7:
		printf("\n\tA winner is just a loser who tried one more time.\n");
		break;
	case 8:
		printf("\n\tIt's Often the last Key in the bunch that opens the lock\n");
		break;
	case 9:
		printf("\n\tThe greatest Oak was once a little nut who held his ground\n");
		break;
	default:
		printf("\n\tYou may encounter many defeats, but you must not be defeated\n");
		break;

	}
	printf("\033[0m");
	return 0;
}

										/*Border Art*/

int border_art(int border_type)
{
	if (border_type < 0)
	{
		border_type = border_type * (-1);
	}
	if (border_type > 9)
	{
		border_type = border_type % 10;
	}
	
	printf("\033[1;92m");
	switch (border_type)
	{
	case 1:
		printf("\n\t=^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=    =^..^=\n");
		break;
	case 2:
		printf("\n\t'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'._.'\n");
		break;
	case 3:
		printf("\n\t~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~ ~_~\n");
		break;
	case 4:
		printf("\n\t^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^\n");
		break;
	case 5:
		printf("\n\t-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-\n");
		break;
	case 6:
		printf("\n\t----------------------8<-------------[ cut here ]------------------------\n");
		break;
	case 7:
		printf("\n\t<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n");
		break;
	case 8:
		printf("\n\t************************************************************************\n");
		break;
	case 9:
		printf("\n\t<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>\n");
		break;
	default:
		printf("\n\t^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^\n");
		break;

	}
	printf("\033[0m");
	return 0;
}

											/*Checking Integer assignments*/

int c_int(long double user_value, int expression_code)
{
	int return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;
	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the integer variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 2147483647 || user_value < -2147483647)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the integer variable exceeds the limits it can hold");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	return_int = user_value;
	return return_int;
}

								/*Checking UNSIGNED Integer assignments*/

unsigned int c_unsigned_int(long double user_value, int expression_code)
{
	unsigned int return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;
	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the unsigned integer variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 4294967295 || user_value < 0)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the unsigned integer variable exceeds the limits it can hold");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	return_int = user_value;
	return return_int;
}

										/*Checking Short assignments*/

short c_short(long double user_value, int expression_code)
{
	short return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;
	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the short variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 32767 || user_value < -32768)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the short variable exceeds the limits it can hold.");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{

			exit(1);
		}
	}

	return_int = user_value;
	return return_int;
}

										/*Checking UNSIGNED Short assignments*/

unsigned short c_unsigned_short(long double user_value, int expression_code)
{
	unsigned short return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;



	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the unsigned short variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 65535 || user_value < 0)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the unsigned short variable exceeds the limits it can hold.");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{

			exit(1);
		}
	}

	return_int = user_value;
	return return_int;
}

													/*Checking Long assignments*/

long c_long(long double user_value, int expression_code)
{
	long return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;
	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the long variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 2147483647 || user_value < -2147483647)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the long variable exceeds the limits it can hold");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	return_int = user_value;
	return return_int;
}

											/*Checking unsigned Long assignments*/

unsigned long c_unsigned_long(long double user_value, int expression_code)
{
	unsigned long return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;
	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the unsigned long variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 4294967295 || user_value < 0)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the unsigned long variable exceeds the limits it can hold");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	return_int = user_value;
	return return_int;
}

									/*Checking char assignments*/

char c_char(long double user_value, int expression_code)
{
	char return_int;
	char continue_or_break_choice;
	long long decimal_check = user_value;
	if (user_value != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe value trying to be pushed in the char variable is not a whole number. \nThe value after the decimal point will be lost");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	if (user_value > 255 || user_value < -128)
	{
		never_give_up(expression_code+1);
		printf("\nThe data trying to be pushed in the char variable exceeds the limits it can hold");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	return_int = user_value;
	return return_int;
}