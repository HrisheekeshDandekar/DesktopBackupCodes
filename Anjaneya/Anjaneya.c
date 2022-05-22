#include<stdio.h>
#include<string.h>
#include"Anjaneya.h"
#pragma warning(disable : 4996)			


										//Values used throughout the code. (Internal workings of console menu)
#define SINGLE_LEFT_UPPER 218
#define SINGLE_RIGHT_UPPER 191
#define SINGLE_LEFT_LOWER 192
#define SINGLE_RIGHT_LOWER 217
#define SINGLE_HORIZONTAL 196
#define SINGLE_VERTICAL 179
#define DOUBLE_LEFT_UPPER 201
#define DOUBLE_RIGHT_UPPER 187
#define DOUBLE_LEFT_LOWER 200
#define DOUBLE_RIGHT_LOWER 188
#define DOUBLE_HORIZONTAL 205
#define DOUBLE_VERTICAL 186

										//Values used for Array Factorial(#define in Anjaneya.h)
//ARR_SIZE = 130002
//TOTAL_DIGITS = 130000

												//functions for internal workings of console menu
int horizontal_padding(int largest_length);
int title_printing(struct menu_contents menu, int largest_length);
int item_display_format(struct menu_contents menu, int largest_length, int item_number);

												//Function for console menu file inputs
int read_file_in_array(char file_path[500]);


																				//Functions for Array Factorial
int string_to_int_arr(char input_array[ARR_SIZE], int number_array[ARR_SIZE]);
int decrement1(char number_array[102]);
int add_arrays(int answer_array[ARR_SIZE], int temp_array[ARR_SIZE]);
int multiply_and_update(int answer_array[ARR_SIZE], int number_array[102]);



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
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
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
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
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

//   scanf for SHORT INTEGER values

short short_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	short final_return = 0;
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

		printf("\nPlease enter a number -32768 to 32767:");
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
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
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

		if (pre_lim_test < -32768 || pre_lim_test > 32767)
		{
			all_okay_flag = 1;
			printf("\nThe number you are trying to input exceeds the data range short variable can hold\n");
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

//   scanf for UNSIGNED SHORT  values

unsigned short ushort_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	unsigned short final_return = 0;
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

		printf("\nPlease enter a number 0 to 65535:");
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
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
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

		if (pre_lim_test < -32768 || pre_lim_test > 65535)
		{
			all_okay_flag = 1;
			printf("\nThe number you are trying to input exceeds the data range unsigned short variable can hold\n");
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




//   scanf for LONG values
long long_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	long final_return = 0;
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
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
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
			printf("\nThe number you are trying to input exceeds the data range long variable can hold\n");
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

//   scanf for UNSIGNED LONG values

unsigned long ulong_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	unsigned long final_return = 0;
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
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
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
			printf("\nThe number you are trying to input exceeds the data range unsigned unsigned long variable can hold\n");
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

//   scanf for CHAR CODES  values

char charcode_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	char final_return = 0;
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

		printf("\nPlease enter a number -600851475143 to 600851475143:");
		fgets(userinput, 63, stdin);
		length = strlen(userinput);

		if (length < 0 || length > 63) {				//Making sure the input does not exceed the array limits
			printf("\nInput Should be in the range of 0-63 characters\n");
			all_okay_flag = 1;
			continue;
		}

		length--;

		for (index = 0; index < length; ++index)						//Testing if any character other than the numbers , '.', '-' are entered			
		{
			if ((userinput[index] < 45 || userinput[index] >57) || (userinput[index] == 47) || (userinput[index] == 46))
			{
				all_okay_flag = 1;
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			printf("\nInvalid character. Please Enter inputs in from of digits without a space or '.'\n");
			continue;
		}

		if (sscanf(userinput, "%lf", &pre_lim_test) != 1)
		{
			all_okay_flag = 1;
			printf("\nCould not assign the input. Please Make sure it is not empty and try again\n");
			continue;
		}

		if (pre_lim_test < -600851475143LL || pre_lim_test > 600851475143ULL)
		{
			all_okay_flag = 1;
			printf("\nThe number you are trying to input exceeds the data range for the code of char can hold\n");
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
//   scanf for CHAR 
char single_char_scanf()
{
	char userinput;
	printf("\nOnly the first character entered will be assigned.\n");
	printf("Please Enter a character : ");
	scanf("%c", &userinput);
	return userinput;
}



/*In the battle of stamina, the mind decides the victor*/				//Motivational Quotes for error codes

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
		printf("\n\tMany of life's failures are people who did not realize how close they were to success when they gave up\n");
		break;
	case 3:
		printf("\n\tCourage doesn't always roar. \n\tSometimes courage is the quiet voice at the end of the day saying 'I will try again tomorrow'.\n");
		break;
	case 4:
		printf("\n\tSuccess is no accident. \n\tIt is hard work, perseverance, learning, studying, sacrifice and most of all,\n\t love of what you are doing or learning to do.\n");
		break;
	case 5:
		printf("\n\tIn the realm of ideas everything depends on enthusiasm... in the real world all rests on perseverance.\n");
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


									//   scanf for float values
float float_scanf()
{
	char userinput[64];
	long double pre_lim_test = 0;
	float final_return = 0;
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

		printf("\nPlease enter a float:");
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
			printf("\nInvalid character. Please Enter inputs in from of digits\n");
			continue;
		}

		if (sscanf(userinput, "%lf", &pre_lim_test) != 1)
		{
			all_okay_flag = 1;
			printf("\nCould not assign the input. Please Make sure it is not empty and try again\n");
			continue;
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
		never_give_up(expression_code + 1);
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
		never_give_up(expression_code + 1);
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
		never_give_up(expression_code + 1);
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
		never_give_up(expression_code + 1);
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
		never_give_up(expression_code + 1);
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
		never_give_up(expression_code + 1);
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
		never_give_up(expression_code + 1);
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

float c_float(long double user_value, float expression_code)
{
	float return_int;
	char continue_or_break_choice;
	long long decimal_check;
	long long check_float;
	decimal_check = user_value;
	return_int = user_value;
	check_float = return_int;

	if (check_float != decimal_check)
	{
		never_give_up(expression_code);
		printf("\nThe following assignment in the data type float is restuling in corrupted data being stored\n");
		printf("\nPlease re - evaluate the data types to better store the results");
		printf("\nExpression Code = %d", expression_code);
		printf("\nEnter 'T' to terminate ||or|| Press Enter to continue as it is\n");
		scanf("%c", &continue_or_break_choice);
		if ((continue_or_break_choice == 'T') || (continue_or_break_choice == 't'))
		{
			exit(1);
		}
	}
	return return_int;
}



/*CONSOLE MENU*/




int display_console_menu(struct menu_contents menu)
{
	int title_len, item_len, attribute1_len, attribute2_len, rightmost_attribute_len, item_full_len, largest_length, counter;

	title_len = strlen(menu.title);
	largest_length = title_len;

	for (counter = 0; counter < TOTAL_ITEMS; counter++)
	{
		item_len = strlen(menu.item[counter].item);
		attribute1_len = strlen(menu.item[counter].attribute1);
		attribute2_len = strlen(menu.item[counter].attribute2);
		rightmost_attribute_len = strlen(menu.item[counter].attribute_rightmost);
		item_full_len = item_len + attribute1_len + attribute2_len + rightmost_attribute_len;

		if (largest_length <= item_full_len)		//Deciding the largest length to be printed
		{
			largest_length = item_full_len;
		}

		//Making sure all the contests can be properly printed

		if ((title_len > (MAX_BUFFER - 1)) || (item_len > (MAX_BUFFER - 1)) || (attribute1_len > (MAX_BUFFER - 1)) || (attribute2_len > (MAX_BUFFER - 1)) ||
			(rightmost_attribute_len > (MAX_BUFFER - 1)))
		{
			printf("The values trying to be entered in the arrays exceed the max value of 109\nTo make sure each character is displayed,\n ");
			printf("Please make sure the length of a row does not exceed 109 characters");
			printf("\n\n\n");
			return 1;

		}
		if (largest_length > 109)
		{
			printf("\nThe contents are longer than the size of a console hence will result in a bad render of a box\n");
			printf("\nPlease re-evaluate the contents and make them fit under 72 characters per row.\n");
			return 1;
		}
	}



	//Starting to print the menu

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_LEFT_UPPER);											//Upper boundry of Double frame
	for (counter = 0; counter < largest_length + 8; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_UPPER);

	title_printing(menu, largest_length);				//Printing Title



	for (counter = 0; counter < TOTAL_ITEMS; counter++)			//Printing the item row/'s
	{
		item_len = strlen(menu.item[counter].item);
		attribute1_len = strlen(menu.item[counter].attribute1);
		attribute2_len = strlen(menu.item[counter].attribute2);
		rightmost_attribute_len = strlen(menu.item[counter].attribute_rightmost);
		item_full_len = item_len + attribute1_len + attribute2_len + rightmost_attribute_len;

		if (item_full_len != 0)										//Checking if the cell is not empty
		{
			item_display_format(menu, largest_length, counter);
		}
	}



	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_LEFT_LOWER);									//Lower boundry of double frame
	for (counter = 0; counter < largest_length + 8; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_LOWER);


	return 0;
}

int horizontal_padding(int largest_length)
{
	//Horizontal length of the console is 120 characters
	//Vertical length of the console is 30 characters

	int doubleframe_horizontal_length, horizontal_padd_size, vertical_padd_size, counter;

	doubleframe_horizontal_length = largest_length + 8;
	horizontal_padd_size = ((120 - doubleframe_horizontal_length) / 2);


	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	return 0;
}

int item_display_format(struct menu_contents menu, int largest_length, int item_number)
{
	int item_len = strlen(menu.item[item_number].item);
	int attribute1_len = strlen(menu.item[item_number].attribute1);
	int attribute2_len = strlen(menu.item[item_number].attribute2);
	int attribute_rightmost_len = strlen(menu.item[item_number].attribute_rightmost);
	int item_full_length = item_len + attribute1_len + attribute2_len + attribute_rightmost_len;
	int counter;

	horizontal_padding(largest_length);   //Padding to get the table at the centre
																//LINE 1 (Upper parts of single borders)
	printf("%c", DOUBLE_VERTICAL);


	if (item_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of item name single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < item_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (item_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}

	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of attribute1 single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < attribute1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}


	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of attribute2 single frame 
	}
	else
	{
		printf("  ");
	}


	for (counter = 0; counter < attribute2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}


	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}


	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of rightmost attribute single frame 
	}
	else
	{
		printf("  ");
	}
	for (counter = 0; counter < attribute_rightmost_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}

	printf("%c\n", DOUBLE_VERTICAL);


	//LINE 2 (Printing strings)
	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);

	if (item_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].item);		//Item name
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].attribute1);		//Attribute1
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].attribute2);		//Attribute2
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}

	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].attribute_rightmost);		//Attribute_rightmost
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	printf("%c\n", DOUBLE_VERTICAL);

	//LINE 3 (Closing of all the single borders)
	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);


	if (item_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of item name single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < item_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (item_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}

	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of attribute1 single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < attribute1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}


	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of attribute2 single frame 
	}
	else
	{
		printf("  ");
	}


	for (counter = 0; counter < attribute2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}


	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}


	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of rightmost attribute single frame 
		for (counter = 0; counter < attribute_rightmost_len; counter++)
		{
			printf("%c", SINGLE_HORIZONTAL);
		}
		if (attribute_rightmost_len != 0)
		{
			printf("%c", SINGLE_RIGHT_LOWER);
		}
	}
	else
	{
		printf("  ");
	}


	printf("%c\n", DOUBLE_VERTICAL);

	return 0;
}

int title_printing(struct menu_contents menu, int largest_length)
{
	int counter, title_padding, title_len;

	title_len = strlen(menu.title);
	title_padding = ((largest_length + 4) - title_len) / 2;

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Blank Line
	for (counter = 0; counter < (largest_length + 8); counter++)
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("\n");


	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Upper start of Title frame  (LINE 1)
	printf(" ");
	printf("%c", DOUBLE_LEFT_UPPER);
	for (counter = 0; counter < (largest_length + 4); counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", DOUBLE_RIGHT_UPPER);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);


	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);                                  //Printing title (LINE 2)
	printf(" ");
	printf("%c", SINGLE_VERTICAL);
	for (counter = 0; counter < title_padding; counter++)
	{
		printf(" ");
	}
	printf("%s", menu.title);
	for (counter = 0; counter < title_padding; counter++)
	{
		printf(" ");
	}
	//Making sure padding is correct (Total length of the line has to be padded with space. If title.len is odd, one space is given less as lower bound is taken during divition)
	if ((title_len % 2) != ((largest_length + 4) % 2))
	{
		printf(" ");
	}
	printf("%c", SINGLE_VERTICAL);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);


	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Lower Start of  Title frame (LINE 3)
	printf(" ");
	printf("%c", DOUBLE_LEFT_LOWER);
	for (counter = 0; counter < (largest_length + 4); counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", DOUBLE_RIGHT_LOWER);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Blank Line
	for (counter = 0; counter < (largest_length + 8); counter++)
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("\n");

	return 0;
}


				//Taking inputs from a text file in console menu

int read_file_in_array(char file_path[500])
{
	FILE* fp;
	char full_file[500];// = { '\0' };
	//D:\\Programming\\Program control text files\\console_menu_inputs.txt

	fp = fopen(file_path, "r");
	if (fp == NULL)
	{
		printf("file not opened!");
	}
	fread(full_file, sizeof(full_file), 1, fp);
	fclose(fp);
	return full_file;
}

int file_input_console_menu(char file_path[500])
{

	struct menu_contents menu =					//Defination
	{
		.title = "Title",

		.item[0].item = "",.item[0].attribute1 = "",.item[0].attribute2 = "",.item[0].attribute_rightmost = "",
		.item[1].item = "",.item[1].attribute1 = "",.item[1].attribute2 = "",.item[1].attribute_rightmost = "",
		.item[2].item = "",.item[2].attribute1 = "",.item[2].attribute2 = "",.item[2].attribute_rightmost = "",
		.item[3].item = "",.item[3].attribute1 = "",.item[3].attribute2 = "",.item[3].attribute_rightmost = "",
		.item[4].item = "",.item[4].attribute1 = "",.item[4].attribute2 = "",.item[4].attribute_rightmost = "",

		.item[5].item = "",.item[5].attribute1 = "",.item[5].attribute2 = "",.item[5].attribute_rightmost = "",
		.item[6].item = "",.item[6].attribute1 = "",.item[6].attribute2 = "",.item[6].attribute_rightmost = "",
		.item[7].item = "",.item[7].attribute1 = "",.item[7].attribute2 = "",.item[7].attribute_rightmost = "",
		.item[8].item = "",.item[8].attribute1 = "",.item[8].attribute2 = "",.item[8].attribute_rightmost = "",
		.item[9].item = "",.item[9].attribute1 = "",.item[9].attribute2 = "",.item[9].attribute_rightmost = "",
		.item[10].item = "",.item[10].attribute1 = "",.item[10].attribute2 = "",.item[10].attribute_rightmost = ""
	};

	char full_file[500] = { "" };
	strcpy(full_file, read_file_in_array(file_path));

	int full_file_position = 0, temp_array_position = 0;

	int title_filled = 0, item_filled = 0, attribute1_filled = 0, attribute2_filled = 0, rightmost_attribute_filled = 0;

	int position_counter = 0, file_end_flag = 0;

	char temp_array[82] = { '\0' };

	while (file_end_flag == 0)
	{
		if ((full_file[full_file_position] != '~') || (full_file[full_file_position != '`']))
		{
			temp_array[temp_array_position] = full_file[full_file_position];
			temp_array_position++;
			full_file_position++;
		}
		if ((full_file[full_file_position] == '~') && (title_filled == 0))
		{
			title_filled = 1;
			temp_array[temp_array_position] = '\0';
			strcpy(menu.title, temp_array);
			full_file_position++;
			temp_array_position = 0;
		}
		else if ((full_file[full_file_position] == '~') && (item_filled == 0))
		{
			temp_array[temp_array_position] = '\0';
			strcpy(menu.item[position_counter].item, temp_array);
			full_file_position++;
			item_filled = 1;
			temp_array_position = 0;
		}
		else if ((full_file[full_file_position] == '~') && (attribute1_filled == 0))
		{
			temp_array[temp_array_position] = '\0';
			strcpy(menu.item[position_counter].attribute1, temp_array);
			full_file_position++;
			attribute1_filled = 1;
			temp_array_position = 0;
		}
		else if ((full_file[full_file_position] == '~') && (attribute2_filled == 0))
		{
			temp_array[temp_array_position] = '\0';
			strcpy(menu.item[position_counter].attribute2, temp_array);
			full_file_position++;
			attribute2_filled = 1;
			temp_array_position = 0;
		}
		else if ((full_file[full_file_position] == '~') && (rightmost_attribute_filled == 0))
		{
			temp_array[temp_array_position] = '\0';
			strcpy(menu.item[position_counter].attribute_rightmost, temp_array);
			full_file_position++;
			rightmost_attribute_filled = 1;
			temp_array_position = 0;
		}
		if ((item_filled == 1) && (attribute1_filled == 1) && (attribute2_filled == 1) && (rightmost_attribute_filled == 1))
		{
			item_filled = 0;
			attribute1_filled = 0;
			attribute2_filled = 0;
			rightmost_attribute_filled = 0;
			position_counter++;
		}
		if ((full_file[full_file_position] == '`'))
		{
			file_end_flag = 1;
		}
	}

	display_console_menu(menu);

}

		//Storing result in a file
int store_result_in_file(char file_position[500], char content_array[130002])
{
	FILE* file = fopen(file_position, "w");
	int results = fputs(content_array, file);
	if (results == EOF)
	{
		printf("\nCould not write");
		printf("\nMake sure you include 'double forward slash' instead of 'single forward slash' in path of the file \n");
	}
	fclose(file);
}


								/*MATH OPERATIONS IN ARRAYS*/
			
				//Converting strings to int arrays for use of some older snipets of code. Will be amended in the newer versions of the library
int string_to_int_arr(char input_array[ARR_SIZE], int number_array[ARR_SIZE])
{
	int initial_total_digits = strlen(input_array);
	int answer_array[ARR_SIZE];
	int counter;

	if (initial_total_digits > TOTAL_DIGITS)
	{
		printf("\nThe input is larger than what the array can hold.\nPlease refer to the #define TOTAL_DIGITS in the headder file for the max limit.\n");
		exit(1);
	}
	number_array[TOTAL_DIGITS] = initial_total_digits;										//100th position of the array will contain the total digits the array holds.
	if ((initial_total_digits == 1) && (input_array[0] == '0'))						//0 factorial =1
	{
		printf("\n0!=1");
		return 1;
	}
	for (counter = 0; counter < initial_total_digits; counter++)				//Making sure only digits are there in the input array
	{
		if ((input_array[counter] < 48) || (input_array[counter] > 57))
		{
			printf("\nA non digit has been passed in the input array.");
			printf("\nThe non digit in the array is '%c' at the %d position of the array", input_array[counter], counter);
			exit(1);
		}

	}
	for (counter = 0; counter < initial_total_digits; counter++)	//Converting numbers string into int array
	{
		number_array[counter] = input_array[counter] - 48;
	}
}

//Array Factorial
char array_factorial(char input_array[102], char answer_string[ARR_SIZE])
{
	int initial_total_digits = strlen(input_array);
	int answer_array[ARR_SIZE];
	int number_array[102];
	//char answer_string[ARR_SIZE];												//Converting int array to a string for writing in a text file
	int counter;

	if (initial_total_digits > 100)
	{
		printf("\nThe input is larger than 100 digits.\nPlease Make sure it is not.\n");
		exit(1);
	}
	number_array[100] = initial_total_digits;										//100th position of the array will contain the total digits the array holds.
	if ((initial_total_digits == 1) && (input_array[0] == '0'))						//0 factorial =1
	{
		printf("\n0!=1");
		return 1;
	}
	for (counter = 0; counter < initial_total_digits; counter++)				//Making sure only digits are there in the input array
	{
		if ((input_array[counter] < 48) || (input_array[counter] > 57))
		{
			printf("\nA non digit has been passed in the input array.");
			printf("\nThe non digit in the array is '%c' at the %d position of the array", input_array[counter], counter);
			exit(1);
		}

	}
	for (counter = 0; counter < initial_total_digits; counter++)	//Converting numbers string into int array
	{
		number_array[counter] = input_array[counter] - 48;
	}

	//Checks Done, satrt of factorial calculation\\


	for (counter = 0; counter < initial_total_digits; counter++)			//Copying number into asnwer array
	{
		answer_array[counter] = number_array[counter];
	}
	answer_array[TOTAL_DIGITS] = number_array[100];								//Answer length same as number for now
	while ((number_array[0] != 1) || (number_array[100] != 1))			//Loop Runs till the number is not 1
	{
		decrement1(number_array);
		multiply_and_update(answer_array, number_array);
	}

	for (counter = 0; counter < answer_array[TOTAL_DIGITS]; counter++)
	{
		answer_string[counter] = answer_array[counter] + 48;
	}

	answer_string[answer_array[TOTAL_DIGITS]] = '\0';		//Indicating the end of valid characters


}

int decrement1(int number_array[102])				//Decrementing the number by 1 (int array)
{
	int reverse_counter = number_array[100] - 1;
	int zero_counter = 0;
	while (1)
	{
		if (number_array[reverse_counter] != 0)
		{
			if ((zero_counter == number_array[100] - 1) && (number_array[0] == 1) && ((number_array[100] - 1) != 0))
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


int multiply_and_update(int answer_array[ARR_SIZE], int number_array[102])
{


	int temp_answer_array[ARR_SIZE];	//To store the answer of multiplication of ans array with each digit of num array then finally replacing asnwer array with it
	temp_answer_array[TOTAL_DIGITS] = 0;
	int reverse_array[ARR_SIZE];
	reverse_array[TOTAL_DIGITS] = 0;
	int temp_answer;
	int carry = 0;
	int counter_num, counter_ans, counter_rev = 0, counter_carry;

	for (counter_num = (number_array[100] - 1); counter_num >= 0; counter_num--)								//Looping through all the digits in the num array from units place
	{
		carry = 0;
		counter_rev = 0;
		for (counter_ans = answer_array[TOTAL_DIGITS] - 1; counter_ans >= 0; counter_ans--)				//Looping through all the digits in the ans array from units place, multiplying it the current num array digit
		{
			temp_answer = (number_array[counter_num] * answer_array[counter_ans]) + carry;
			reverse_array[counter_rev] = temp_answer % 10;
			counter_rev++;
			reverse_array[TOTAL_DIGITS] = reverse_array[TOTAL_DIGITS] + 1;
			carry = temp_answer / 10;
			if ((counter_ans == 0) && (carry != 0))												//Adding the carry if all the ans array numbers have been multiplied with 					
			{
				reverse_array[reverse_array[TOTAL_DIGITS]] = carry;
				reverse_array[TOTAL_DIGITS] = reverse_array[TOTAL_DIGITS] + 1;
			}
		}
		for (counter_carry = 0; counter_carry < (reverse_array[TOTAL_DIGITS] / 2); counter_carry++)							//Reversing the reverse array
		{
			temp_answer = reverse_array[counter_carry];
			reverse_array[counter_carry] = reverse_array[reverse_array[TOTAL_DIGITS] - counter_carry - 1];
			reverse_array[reverse_array[TOTAL_DIGITS] - counter_carry - 1] = temp_answer;
		}
		for (counter_carry = 0; counter_carry < (number_array[100] - 1 - counter_num); counter_carry++)					//Adding 0's to the end of ans depending on the location of the num_array digit
		{
			reverse_array[reverse_array[TOTAL_DIGITS]] = 0;
			reverse_array[TOTAL_DIGITS] = reverse_array[TOTAL_DIGITS] + 1;
		}
		add_arrays(temp_answer_array, reverse_array);
		reverse_array[TOTAL_DIGITS] = 0;
	}
	answer_array[TOTAL_DIGITS] = temp_answer_array[TOTAL_DIGITS];
	for (counter_ans = 0; counter_ans < answer_array[TOTAL_DIGITS]; counter_ans++)
	{
		answer_array[counter_ans] = temp_answer_array[counter_ans];
	}

}

int add_arrays(int answer_array[ARR_SIZE], int temp_array[ARR_SIZE])
{
	int carry = 0;
	int temp, largest_length, counter_smaller_array, counter_larger_array;
	if (answer_array[TOTAL_DIGITS] >= temp_array[TOTAL_DIGITS])
	{
		counter_larger_array = answer_array[TOTAL_DIGITS] - 1;
		largest_length = answer_array[TOTAL_DIGITS];
		for (counter_smaller_array = temp_array[TOTAL_DIGITS] - 1; counter_smaller_array >= 0; counter_smaller_array--)
		{
			temp = answer_array[counter_larger_array] + temp_array[counter_smaller_array];
			temp = temp + carry;
			answer_array[counter_larger_array] = temp % 10;
			carry = temp / 10;
			counter_larger_array--;
		}
		if (carry != 0)
		{
			for (counter_larger_array = (answer_array[TOTAL_DIGITS] - temp_array[TOTAL_DIGITS] - 1); counter_larger_array >= 0; counter_larger_array--)
			{
				temp = answer_array[counter_larger_array] + carry;
				answer_array[counter_larger_array] = temp % 10;
				carry = temp / 10;
			}
			if (carry != 0)
			{
				for (counter_smaller_array = answer_array[TOTAL_DIGITS]; counter_smaller_array > 0; counter_smaller_array--)
				{
					answer_array[counter_smaller_array] = answer_array[counter_smaller_array - 1];
				}
				answer_array[0] = carry;
				answer_array[TOTAL_DIGITS] = answer_array[TOTAL_DIGITS] + 1;
			}
		}
	}
	else
	{
		counter_larger_array = temp_array[TOTAL_DIGITS] - 1;
		largest_length = temp_array[TOTAL_DIGITS];
		for (counter_smaller_array = answer_array[TOTAL_DIGITS] - 1; counter_smaller_array >= 0; counter_smaller_array--)
		{
			temp = temp_array[counter_larger_array] + answer_array[counter_smaller_array];
			temp = temp + carry;
			temp_array[counter_larger_array] = temp % 10;
			carry = temp / 10;
			counter_larger_array--;
		}
		if (carry != 0)
		{
			for (counter_larger_array = (temp_array[TOTAL_DIGITS] - answer_array[TOTAL_DIGITS] - 1); counter_larger_array >= 0; counter_larger_array--)
			{
				temp = temp_array[counter_larger_array] + carry;
				temp_array[counter_larger_array] = temp % 10;
				carry = temp / 10;
			}
			if (carry != 0)
			{
				for (counter_smaller_array = temp_array[TOTAL_DIGITS]; counter_smaller_array > 0; counter_smaller_array--)
				{
					temp_array[counter_smaller_array] = temp_array[counter_smaller_array - 1];
				}
				temp_array[0] = carry;
				temp_array[TOTAL_DIGITS] = temp_array[TOTAL_DIGITS] + 1;
			}
		}
		answer_array[TOTAL_DIGITS] = temp_array[TOTAL_DIGITS];
		for (counter_larger_array = 0; counter_larger_array < answer_array[TOTAL_DIGITS]; counter_larger_array++)
		{
			answer_array[counter_larger_array] = temp_array[counter_larger_array];
		}
	}

}

					//Adding Numbers through Arrays


int add_positive_arrays(int answer_array[ARR_SIZE], int number1[ARR_SIZE], int number2[ARR_SIZE])
{
	int carry = 0;
	int temp, largest_length, counter_smaller_array, counter_larger_array;
	int number1_temp[ARR_SIZE];
	for (carry = 0; carry < number1[TOTAL_DIGITS]; carry++)
	{
		number1_temp[carry] = number1[carry];
	}
	number1_temp[TOTAL_DIGITS] = number1[TOTAL_DIGITS];
	carry = 0;
	if (number1[TOTAL_DIGITS] >= number2[TOTAL_DIGITS])
	{
		counter_larger_array = number1[TOTAL_DIGITS] - 1;
		largest_length = number1[TOTAL_DIGITS];
		for (counter_smaller_array = number2[TOTAL_DIGITS] - 1; counter_smaller_array >= 0; counter_smaller_array--)
		{
			temp = number1[counter_larger_array] + number2[counter_smaller_array];
			temp = temp + carry;
			number1[counter_larger_array] = temp % 10;
			carry = temp / 10;
			counter_larger_array--;
		}
		if (carry != 0)
		{
			for (counter_larger_array = (number1[TOTAL_DIGITS] - number2[TOTAL_DIGITS] - 1); counter_larger_array >= 0; counter_larger_array--)
			{
				temp = number1[counter_larger_array] + carry;
				number1[counter_larger_array] = temp % 10;
				carry = temp / 10;
			}
			if (carry != 0)
			{
				for (counter_smaller_array = number1[TOTAL_DIGITS]; counter_smaller_array > 0; counter_smaller_array--)
				{
					number1[counter_smaller_array] = number1[counter_smaller_array - 1];
				}
				number1[0] = carry;
				number1[TOTAL_DIGITS] = number1[TOTAL_DIGITS] + 1;
			}
		}
		for (counter_larger_array = 0; counter_larger_array < number1[TOTAL_DIGITS]; counter_larger_array++)
		{
			answer_array[counter_larger_array] = number1[counter_larger_array];
		}
		answer_array[TOTAL_DIGITS] = number1[TOTAL_DIGITS];
		for (counter_larger_array = 0; counter_larger_array < number1_temp[TOTAL_DIGITS]; counter_larger_array++)
		{
			number1[counter_larger_array] = number1_temp[counter_larger_array];
		}
		number1[TOTAL_DIGITS] = number1_temp[TOTAL_DIGITS];
	}
	else
	{
		counter_larger_array = number2[TOTAL_DIGITS] - 1;
		largest_length = number2[TOTAL_DIGITS];
		for (counter_smaller_array = number1[TOTAL_DIGITS] - 1; counter_smaller_array >= 0; counter_smaller_array--)
		{
			temp = number2[counter_larger_array] + number1[counter_smaller_array];
			temp = temp + carry;
			number2[counter_larger_array] = temp % 10;
			carry = temp / 10;
			counter_larger_array--;
		}
		if (carry != 0)
		{
			for (counter_larger_array = (number2[TOTAL_DIGITS] - number1[TOTAL_DIGITS] - 1); counter_larger_array >= 0; counter_larger_array--)
			{
				temp = number2[counter_larger_array] + carry;
				number2[counter_larger_array] = temp % 10;
				carry = temp / 10;
			}
			if (carry != 0)
			{
				for (counter_smaller_array = number2[TOTAL_DIGITS]; counter_smaller_array > 0; counter_smaller_array--)
				{
					number2[counter_smaller_array] = number2[counter_smaller_array - 1];
				}
				number2[0] = carry;
				number2[TOTAL_DIGITS] = number2[TOTAL_DIGITS] + 1;
			}
		}
		number1[TOTAL_DIGITS] = number2[TOTAL_DIGITS];
		for (counter_larger_array = 0; counter_larger_array < number1[TOTAL_DIGITS]; counter_larger_array++)
		{
			number1[counter_larger_array] = number2[counter_larger_array];
		}
		for (counter_larger_array = 0; counter_larger_array < number1[TOTAL_DIGITS]; counter_larger_array++)
		{
			answer_array[counter_larger_array] = number1[counter_larger_array];
		}
		answer_array[TOTAL_DIGITS] = number1[TOTAL_DIGITS];
		for (counter_larger_array = 0; counter_larger_array < number1_temp[TOTAL_DIGITS]; counter_larger_array++)
		{
			number1[counter_larger_array] = number1_temp[counter_larger_array];
		}
		number1[TOTAL_DIGITS] = number1_temp[TOTAL_DIGITS];


	}
}

