#pragma once
#pragma once
//FUNCTIONS\\

int never_give_up(int error_no);			//Quotes
int border_art(int border_type);			//Border function


										/*Assignment Fucntions for '=' operator*/
long double check_assign;
int c_int(long double user_value, int expression_code);
unsigned int c_unsigned_int(long double user_value, int expression_code);
short c_short(long double user_value, int expression_code);
unsigned short c_unsigned_short(long double user_value, int expression_code);
long c_long(long double user_value, int expression_code);
unsigned long c_unsigned_long(long double user_value, int expression_code);
char c_char(long double user_value, int expression_code);
float c_float(long double user_value, float expression_code);



/*Scanf for common data types*/
int int_scanf();
unsigned int uint_scanf();
short short_scanf();
unsigned short ushort_scanf();
long long_scanf();
unsigned long ulong_scanf();
char charcode_scanf();
char single_char_scanf();
float float_scanf();


//Console Menu
int display_console_menu(struct menu_contents menu);
#define TOTAL_ITEMS 11
#define MAX_BUFFER 116
struct item_contents
{
	char item[MAX_BUFFER];
	char attribute1[MAX_BUFFER];
	char attribute2[MAX_BUFFER];
	char attribute_rightmost[MAX_BUFFER];
};

struct menu_contents
{
	char title[MAX_BUFFER];
	struct item_contents item[TOTAL_ITEMS];
};

//Console menu File inputs
int file_input_console_menu(char file_path[500]);

//Array Factorial
#define ARR_SIZE 130002
#define TOTAL_DIGITS 130000
char array_factorial(char input_array[102], char answer_array[ARR_SIZE]);

//Addition through Arrays
int add_positive_arrays(int answer_array[ARR_SIZE], int number1[ARR_SIZE], int number2[ARR_SIZE]);

//Storing any restult in a file
int store_result_in_file(char file_position[500], char content_array[ARR_SIZE]);
