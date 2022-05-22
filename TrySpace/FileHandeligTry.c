/* Program to test out r+b mode and make sure it works as intended
 * [TODO] : Memory Locking at a perticular file pointer
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _File_contents 
{
	char* file_contents;
	long value;
} File_contents;

typedef struct _File_positions 
{
	FILE* fp_file_contents;
	FILE* fp_value;
} File_positions;

void default_innit(File_contents* default_content);
void expected_innit(File_contents* expected_content);
void locations_innit(File_positions* locations);
void write_default(FILE* fp, File_contents* default_content);
void print_file(FILE* fp);
void locate_addresses(FILE* fp, File_positions* locations);
void update_file(FILE* fp, File_positions* locations, long new_value);
void verify_update(FILE* fp, File_contents* expected_content);
void mem_release(File_contents* default_content, File_contents* expected_content);

int main()
{
	printf("\n\t Compile and Run\n");
	File_contents default_content;
	File_contents expected_content;
	File_positions locations;

	//Memory Innitialization
	default_innit(&default_content);
	locations_innit(&locations); //All set to null for now
    expected_innit(&expected_content); //Updated Value

	//Trying to open in Binary (r+b)
	FILE* fp = fopen("BinaryTestFile.bin", "r+b");
	if (!fp)
	{
		perror("[r+b open failed]"); fclose(fp); return 1;
	}

	write_default(fp, &default_content);

	//Print file contents
	print_file(fp);

	//Capture Locations
	locate_addresses(fp, &locations);

	//Update file
	update_file(fp, &locations, 1234567890);

	//Print file contents
	print_file(fp);

	//Verify binary file with expected contents after updation
	verify_update(fp, &expected_content);

	//Release Memory
	mem_release(&default_content, &expected_content);
	return 0;
}

void default_innit(File_contents* default_content)
{
	default_content->file_contents = (char*) malloc(sizeof(char) * 50);
	strcpy(default_content->file_contents, "Hrisheekesh Dandekar");
	default_content->value = 69420;
}

void expected_innit(File_contents* expected_content)
{
	expected_content->file_contents = (char*) malloc(sizeof(char) * 50);
	strcpy(expected_content->file_contents, "Hrisheekesh Dandekar");
	expected_content->value = 123457890;
}

void locations_innit(File_positions* locations)
{
	locations->fp_file_contents = NULL;
	locations->fp_value = NULL;
}

void write_default(FILE* fp, File_contents* default_content)
{

}

void print_file(FILE* fp)
{

}

void locate_addresses(FILE* fp, File_positions* locations);
void update_file(FILE* fp, File_positions* locations, long new_value);
void verify_update(FILE* fp, File_contents* expected_content);
void mem_release(File_contents* default_content, File_contents* expected_content);

