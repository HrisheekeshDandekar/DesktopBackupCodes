#include <stdio.h>
#include <stdlib.h>

int somefunc( int print_tis );

int main(int argc, char** argv)
{
	printf("\n\n\n\t---===[ Please Fix ]===---\n\n\n");
	remove(argv[0]);
	//scanf("%c", &x);
	getc(stdin);
	somefunc(69);
	return 0;
}

int somefunc( int print_tis )
{
	if(print_tis < 0) {
		return 420;
	}

	printf("\n\t%d", print_tis);
	somefunc(print_tis--);
	return 69;
}
