#pragma warning(disable : 4996)																				
/***************************************************
*
*					//Conditions\\
*	1)Start should not be closing brace vice versa
*	2)Every opning brace should have a closing
*	3)There should not be more closing at any point going from left to right
*
****************************************************/
#include<stdio.h>					
#include<string.h>
//
//#define UP_ARROW 94
//
//int enter_n_check();
//int check_one_eq(char input[100]);
//int check_brace(char to_check, char brace_open, char brace_close, int* brace_counter, int* check_passed);
//int display_error(char equation[100], int position);
//int check_eq_reverse(char input[100]);
//int check_brace_reverse(char to_check, char brace_open, char brace_close, int* brace_counter, int* check_passed);
//
//
//int main()
//{
//	enter_n_check();
//	return 0;
//}
//int enter_n_check()
//{
//	char stop = 0;
//	char input[100];
//	int check;
//	while (stop != 'n' && stop != 'n')
//	{
//		printf("\nenter your equation : ");
//		scanf("%[^\n]s", &input);
//		getchar();
//		check = check_one_eq(input);
//		if (check == 0)
//		{
//			printf("\nequation is -----{\033[0;32m balanced \033[0m}-----\n");
//		}
//		else if (check > 0)
//		{
//			printf("\nequation is -----{\033[0;31m un - balanced \033[0m}-----\n");
//			display_error(input, check);
//		}
//		else
//		{
//			printf("\nequation is -----{\033[0;31m un - balanced \033[0m}-----\n");
//			check=check_eq_reverse(input);
//			display_error(input, check);
//		}
//		printf("\nTry another eq? (enter n to stop)\n");
//		scanf("%c", &stop);
//		getchar();
//
//	}
//	return 0;
//}
//int check_one_eq(char input[100])
//{
//	int i;
//	int size;
//	size = strlen(input);
//	//printf("\nsize : %d\n", size);
//	//printf("\nstring : %s\n", input);
//
//	int normal_brace = 0;
//	int curly = 0;
//	int square_brace = 0;
//	int angular = 0;
//	int check_passed=0;
//
//	char normal_brace_open = '(';
//	char normal_brace_close = ')';
//
//	char curly_open = '{';
//	char curly_close = '}';
//
//	char square_open = '[';
//	char square_close = ']';
//
//	char anglar_open = '<';
//	char anglar_close = '>';
//									
//
//	for (i = 0; i < size; i++)											//try passing the char itself later (no need for variables)
//	{
//		switch (input[i])
//		{
//
//		case '(':
//			check_brace(input[i], '(', ')', &normal_brace, &check_passed);
//			break;
//		case ')':
//			check_brace(input[i], '(', ')', &normal_brace, &check_passed);
//			break;
//
//		case  '{':
//			check_brace(input[i],'{', '}', &curly, &check_passed);
//			break;
//		case  '}':
//			check_brace(input[i], '{', '}', &curly, &check_passed);
//			break;
//		
//		case '[':
//			check_brace(input[i], '[', ']', &square_brace, &check_passed);
//			break;
//		case ']':
//			check_brace(input[i], '[', ']', &square_brace, &check_passed);
//			break;
//
//		case '<':
//			check_brace(input[i], '<', '>', &angular, &check_passed);
//			break;
//		case '>':
//			check_brace(input[i], '<', '>', &angular, &check_passed);
//			break;
//		}
//		if (check_passed == 1)
//		{
//			break;
//		}
//	}
//	if ((normal_brace == 0) && (curly == 0) && (square_brace == 0) && (angular == 0))
//	{
//		check_passed = 0;
//	}
//	else if((normal_brace < 0) || (curly < 0) || (square_brace < 0) || (angular < 0))
//	{
//		check_passed = i + 2;
//	}
//	else
//	{
//		check_passed = -1;			//need to check equation from right to left to find error position
//	}
//	return check_passed;
//}
//
//int check_brace(char to_check,char brace_open,char brace_close,int *brace_counter,int *check_passed)
//{
//	if (to_check == brace_open)
//	{
//		*brace_counter+=1;
//		//if (*brace_counter < 0)
//		//{
//		//	*check_passed = 1;
//		//}
//	}
//	else if (to_check == brace_close)
//	{
//		*brace_counter-=1;
//		if (*brace_counter < 0)
//		{
//			*check_passed = 1;
//		}
//	}
//}
//
//int display_error(char equation[100],int position)		//displaying error position based on its co-ordinate
//{
//	position -= 1;						//if error at position 0, 0+1 is passed as 0 is our code for balanced eq
//	printf("\n\t%s\n", equation);
//	printf("\t");							
//	for (int j = 0; j < position - 1; j++)		
//	{
//		printf(" ");
//	}
//	printf("%c\n", UP_ARROW);
//	for (int j = 0; j < position + 5; j++)
//	{
//		printf(" ");
//	}
//	printf("error\n");
//}
//
//int check_eq_reverse(char input[100])
//{
//	int i;
//	int size;
//	size = strlen(input);
//
//	int normal_brace = 0;
//	int curly = 0;
//	int square_brace = 0;
//	int angular = 0;
//	int check_passed = 0;
//
//	char normal_brace_open = '(';
//	char normal_brace_close = ')';
//
//	char curly_open = '{';
//	char curly_close = '}';
//
//	char square_open = '[';
//	char square_close = ']';
//
//	char anglar_open = '<';
//	char anglar_close = '>';
//
//
//	for (i = size-1; i >-1; i--)
//	{
//		switch (input[i])
//		{
//
//		case '(':
//			check_brace_reverse(input[i], '(', ')', &normal_brace, &check_passed);
//			break;
//		case ')':
//			check_brace_reverse(input[i], '(', ')', &normal_brace, &check_passed);
//			break;
//
//		case  '{':
//			check_brace_reverse(input[i], '{', '}', &curly, &check_passed);
//			break;
//		case  '}':
//			check_brace_reverse(input[i], '{', '}', &curly, &check_passed);
//			break;
//
//		case '[':
//			check_brace_reverse(input[i], '[', ']', &square_brace, &check_passed);
//			break;
//		case ']':
//			check_brace_reverse(input[i], '[', ']', &square_brace, &check_passed);
//			break;
//
//		case '<':
//			check_brace_reverse(input[i], '<', '>', &angular, &check_passed);
//			break;
//		case '>':
//			check_brace_reverse(input[i], '<', '>', &angular, &check_passed);
//			break;
//		}
//		if (check_passed == 1)
//		{
//			break;
//		}
//	}
//	if ((normal_brace == 0) && (curly == 0) && (square_brace == 0) && (angular == 0))		//equation balanced
//	{
//		check_passed = 0;
//	}
//	else if ((normal_brace < 0) || (curly < 0) || (square_brace < 0) || (angular < 0))			//extra opning brace error case
//	{
//		check_passed = i + 2;
//	}
//	else			//extra closing brace err case
//	{
//		check_passed = -1;			//need to check equation from right to left to find error position
//	}
//	return check_passed;
//}
//
//
//int check_brace_reverse(char to_check, char brace_open, char brace_close, int* brace_counter, int* check_passed)
//{
//	if (to_check == brace_open)
//	{
//		*brace_counter -= 1;
//		if (*brace_counter < 0)
//		{
//			*check_passed = 1;
//		}
//	}
//	else if (to_check == brace_close)
//	{
//		*brace_counter += 1;
//		//if (*brace_counter < 0)							//do i need to check less than 0 here?
//		//{
//		//	*check_passed = 1;
//		//}
//	}
//}

//int main()
//{
//
//	int a = 5;
//	_asm {
//		mov eax, 5;
//		mov ecx, dword ptr[a];
//		mov dword ptr[a], 10;
//		add ecx, eax;
//		add dword ptr[a], ecx;
//	}
//	printf("%d", a);
//	return 0;
//
//}
//}



//int check_brace(char to_check, char brace_open, char brace_close, int* brace_counter, int* check_passed)
//{
//	if (to_check == brace_open)
//	{
//		*brace_counter += 1;
//		if (*brace_counter < 0) 
//		{
//			*check_passed = 1;
//		}
//	}
//	else if (to_check == brace_close)
//	{
//		*brace_counter -= 1;
//		if (*brace_counter < 0)
//		{
//			*check_passed = 1;
//		}
//	}
//}


/*if (input[i] == '(')
{
	normal_brace++;
	if (normal_brace < 0)
	{
		return 1;
	}
}
else if (input[i] == ')')
{
	normal_brace--;
	if (normal_brace < 0)
	{
		return 1;
	}
}
else if (input[i] == '{')
{
	curly++;
	if (curly < 0)
	{
		return 1;
	}
}
else if (input[i] == '}')
{
	curly--;
	if (curly < 0)
	{
		return 1;
	}
}
else if (input[i] == '[')
{
	square_brace++;
	if (square_brace < 0)
	{
		return 1;
	}
}
else if (input[i] == ']')
{
	square_brace--;
	if (square_brace < 0)
	{
		return 1;
	}
}
else if (input[i] == '<')
{
	angular++;
	if (angular < 0)
	{
		return 1;
	}
}
else if (input[i] == '>')
{
	angular--;
	if (angular < 0)
	{
		return 1;
	}
}*/