/*Take an image. encrpyt it by adding 69 to each byte. store back*/
#include <stdio.h>
#include <stdbool.h>

bool binary_encrypt_via_rotation(FILE* fp);

int main(int argc, char**argv)
{
	if (argc != 2)
	{
		printf("[NO FILE NAME PASSED]\nCorrect usage: ./program_name < file_name >\n");
		return 1;
	}

	FILE* fp = fopen(argv[1], "r+");
	if (!fp)
	{
		printf("[ERROR] could not open file: %s\n", argv[1]);
		return 1;
	}
	//FILE* fp = fopen(argv[1], "rb+");

	binary_encrypt_via_rotation(fp);
	return 0; 

}

bool binary_encrypt_via_rotation(FILE* fp)
{
	//int mult_by = 1;
	//int add_by = 20;
	char file_byte = 'X';
	int current_offset = 0;
	while (!feof(fp))
	{
		fseek(fp, current_offset, SEEK_SET);
		fread(&file_byte, sizeof file_byte, 1, fp);
		file_byte *= mul_num;
		//printf("%p ) %c\n", fp, file_byte);		
		//printf("\tFtell : %d\n", ftell(fp));
		current_offset++;
	}
	return true;
}





