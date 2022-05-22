#include<stdio.h>

int main()
{
	struct menu_item
	{
		char id[3];
		int sr_no;
	};

	struct menu
	{
		char title[10];
		struct menu_item item[3];

	};

	//char array[1][10] = { "Title","item1","Attribute1" };

	struct menu_item try1 = { .id = "abc",.sr_no = 1324 };
	//try1.id = { "abc"};

	//struct menu a = { .title = "Title",.id = "Num",.sr_no = 00 };
	//printf("%s %s %d", a.title, a.id, a.sr_no);

	//printf("%s %d", try1.id,try1.sr_no);

	struct menu_item arr[3] =
	{ {.id="a",.sr_no=1}, {.id = "b",.sr_no = 2}, {.id = "c",.sr_no = 3}};
	printf("%s %d\n", arr[0].id, arr[0].sr_no);
	printf("%s %d\n", arr[1].id, arr[1].sr_no);
	printf("%s %d\n", arr[2].id, arr[2].sr_no);

	return 0;
}


