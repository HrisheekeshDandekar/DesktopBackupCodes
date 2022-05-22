#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct MyStruct
{
	int someshit;
}try_struct;

int delete_without_password(int argc, char** argv);
void delete_executable();

int main(int argc, char** argv) {
	//printf("\n Argc : %d"
	//	   "\n Argv[0] : %s"
	//	   "\n Argv[1] : %s\n"
	//	   , argc, argv[0], argv[1]);

	printf("\n\t Stupid Hello World\n");
	//delete_without_password(argc, argv);
	return 0;
}

int delete_without_password(int argc, char** argv)
{
	if (argc != 2) 
	{
		printf("\n\t Sorry lad, wrong arguments passed. \n\tSoo long....\n\n");
		delete_executable(argc, argv);
		return 1;
	}
	
	//Check if password matches
	char* password = "password";
	
	if (strlen(password) != strlen(argv[1])) 
	{
		printf("\n\t Sorry lad, wrong PASSWORD\n\tSoo long....\n\n");
		delete_executable(argc, argv);
		return 1;
	}
	
	if (strcmp(password, argv[1])) 
	{
		printf("\n\t Sorry lad, wrong PASSWORD\n\tSoo long....\n\n");
		delete_executable(argc, argv);
		return 1;
	}
			
	printf("\nSuper Secreat Msg here\n");
	return 0;
}

void delete_executable(int argc, char** argv)
{
	int ret = remove(argv[0]);
	if (ret) 
	{
		printf("\n\t How da heck did you manage that\n"
			   "\nArgc : %d"
			   "\nFile Name : %s"
			   "\n\tReturn val (from remove) : %d\n\n", argc, argv[1], ret);
	}
}
