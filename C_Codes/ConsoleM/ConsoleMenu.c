#include <stdio.h>
#include <string.h>

const int WIDTH = 80;


const int LEFT_UPPER = 201;
const int RIGHT_UPPER = 187;
const int LEFT_LOWER = 200;
const int RIGHT_LOWER = 188;
const int VERTICAL_SINGLE = 179;
const int HORIZONTAL_SINGLE = 196;
const int HORIZONTAL_DOUBLE = 205;

void    print_in_box		  (char* str);
int     padding_calculated    (char* str);
void    upper_line_printed    (int padding, int len);
void    sentence_printed	  (char* str, int padding);
void    lower_line_printed    (int padding, int len);

int main()
{
	char str[] = "Hello World In a box";
	        [];
	print_in_box(str);
	return 0;
}

void print_in_box(char* str)
{
	int padding = padding_calculated(str);
	int len = strlen(str); 

	upper_line_printed(padding, len);
	sentence_printed(str, padding);
	lower_line_printed(padding, len);
}

int padding_calculated(char* str)
{
   	int itterator = 0;
   	while( str[itterator] != '\0' ) { itterator++; }
	return( (WIDTH - itterator + 2) / 2 );
}

void upper_line_printed(int padding, int len)
{
	printf("\n");
	for( int i = 0; i < padding; i++ ) { printf(" "); }
	printf("%c" , LEFT_UPPER);
	for( int i = 0; i < len ; i++ ) { printf("%c", HORIZONTAL_DOUBLE ); }
	printf("%c\n" , RIGHT_UPPER);	
}

void sentence_printed (char* str, int padding)
{
	for( int i = 0; i < padding; i++ ) { printf(" "); }
	printf("%c" , VERTICAL_DOUBLE);
	printf("%s" , str);
	printf("%c" , VERTICAL_DOUBLE);	//New line printed
}

void lower_line_printed (int padding, int len)
{
	printf("\n");
	for( int i = 0; i < padding; i++ ) { printf(" "); }
	printf("%c" , LEFT_LOWER);
	for( int i = 0; i < len ; i++ ) { printf("%c", HORIZONTAL_DOUBLE ); }
	printf("%c\n\n" , RIGHT_LOWER);	//New Line printed
}
