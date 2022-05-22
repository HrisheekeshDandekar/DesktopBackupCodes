/*   Program to generate unique numbers every time
 *
 *   [ 1234567890 ]
 *      |     |
 *    [123]   |
 *      |   [4567890] (in ram) -> ( set to 0 at start )
 *      |     
 *    (in secondary storage) -> ( incremented each time at start )
 *
 *
 *    [PSUDO CODE]
 *
 *		--- Memory Innitialization ---
 *    > Innitialize ram number to 0
 *    > Open file containing most significant digits of the number 
 *			(if not there, create new with 0 innitialized)
 *			(if rom number at capacity, exit with msg)
 *			(if rom number not at capacity, increment by 1)
 *
 *		--- Operations and Checks ---
 *	  > When random number request appears:
 *	  > Output unique id:
 *			[ Join rom number as most significant digtis ]
 *			[ Join ram number as least significant digtis ]
 *
 *			Check (ram number, rom number) for bounds and increment
 *				[ If rom number is at max capacity, exit with msg ]
 *				[ If ram number is at max capacity, reset to 0 , increment rom number ]
 *				[ check rom number again ]
 */

//				---===[NEEDS WORK]===---
//
// File being innitalized to 1 at the start instead of increment
// learn atexit
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

//Debugg Studd
//long expected_key = 0;	

//Error Codes
#define E_NOERROR 0
#define E_MSD_CAP_REACHED -1
#define E_FILE_HANDELING_FALURE -2

//Most significant digit range
const int MSD_MAX = 999;

//Least significant digit range
const int LSD_MAX = 999999;

//Most Significant digits stored in this file
const char* filename = "Unique_id_current_block.bin";

//Least Significant Digit Innitialized to 0 at start of each run
int lsd = 0;

//Function Prototypes
int  read_n_check_msd(FILE* fp);
bool innitialize_msd_to_zero(FILE* fp);
bool increment_msd(FILE* fp, int* current_msd);
bool provide_more_keys(FILE* fp, int* current_msd);
long unique_key_return(int msd);

int main()
{
	int current_msd = 0;

	//Openeing file
	//FILE* fp = fopen(filename, "rb+");
	FILE* fp = fopen(filename, "rb+");

	//MSD checks
	if (!fp) 
	{
		printf("\n[ FOPEN ERROR ] error number:  %d\n", errno);
		printf("\n( run the code to innitialize the binary file first )\n");
		return E_FILE_HANDELING_FALURE;
	} 
	else 
	{
		current_msd = read_n_check_msd(fp); 
	}	

	if (current_msd == E_MSD_CAP_REACHED) 
	{
		return E_MSD_CAP_REACHED;
	}
		
	//MSD incremented
	if (!increment_msd(fp, &current_msd)) 
	{
		printf("\n\t[FILE HANDELING ERROR]\n");
		return E_FILE_HANDELING_FALURE;
	}
	
	//Provide total number of unique keys requested
	bool b_provide_more_keys = true;

	while (b_provide_more_keys)
	{
		b_provide_more_keys = provide_more_keys(fp, &current_msd);
	}

	//Close file
	//atexit(fclose(fp)); [TODO]
	fclose(fp);
	
	return 0;
}

int read_n_check_msd(FILE* fp)
{
	int msd = E_FILE_HANDELING_FALURE;
	fseek(fp, 0, SEEK_SET);
	int elements_read = fread(&msd, sizeof(int), 1, fp);

	if (elements_read != 1 || msd == E_FILE_HANDELING_FALURE) 
	{
		printf("\n\t[Data In File is corrupt]\n");
		return E_FILE_HANDELING_FALURE;
	}

	if (msd >= MSD_MAX) 
	{
		printf("\n\t[UNIQUE NUMBERS LIMIT REACHED]\n");
		return E_MSD_CAP_REACHED;
	}

	return msd;
}

bool innitialize_msd_to_zero(FILE* fp)
{
	int msd = 0;
	
	//Writing int to newly created file
	fseek(fp, 0, SEEK_SET);
	int elements_written = fwrite(&msd, sizeof(int), 1, fp);

	//Making sure value is written properly
	if (elements_written != 1) 
	{
		printf("\n\t[FWRITE ERROR]\n");
		return false;
	}

	return true;
}

bool provide_more_keys(FILE* fp, int* current_msd)
{

	//[TODO] : Learn How to accept multiple requests at a time
	//
	// -- temp solution --
	//   > int input of current number of requests

	long unique_key = 0;
	int requests = 0;
	while(requests < 1)
	{
		printf("\n\tEnter the number ( positive int ) of unique numbers to be returned :");
		scanf("%d", &requests);
		if (requests < 1) 
		{
			printf("\n\t[ Request must be a positive number ]");
		}
	}

	for (int i = 0; i < requests; i++) 
	{
		unique_key = unique_key_return(*current_msd);
		lsd++;

		//Checking if msd or lsd has reached its limit
		if (*current_msd > MSD_MAX) 
		{
			printf("\n\t[ UNIQUE NUMBERS EXHAUSTED ]\n");
			return false;
		}
		else if (lsd == LSD_MAX) 
		{
			if (!increment_msd(fp, current_msd)) 
			{
				printf("\n[ ERROR ] could not increment msd\n");
				return false;
			}
			else 
			{
				lsd = 0;
			}
		}

		printf("\n\t[ SUCCESS ] Unique Key is : ( %ld )\n", unique_key);

		//Debug stuff
		//if (unique_key != expected_key) 
		//{
		//	printf("\n[ WRONG KEY ] expected : %ld\n got : %ld", expected_key, unique_key);
		//	getchar();
		//}
		//expected_key++;
		//Debug End
	}
	return true;
}

long unique_key_return(int msd)
{
	long unique_key = msd * 100000; 
	unique_key += lsd; 
	return unique_key;
}

bool increment_msd(FILE* fp, int* current_msd)
{
	int msd_in_file = -2;	
	fseek(fp, 0, SEEK_SET);

	int elements_read = fread(&msd_in_file, sizeof(int), 1, fp);

	//Testing retrived data
	if (elements_read != 1) 
	{
		printf("\n\t[Data In File is corrupt]\n");
		return false;
	}
	if (msd_in_file != *current_msd)
	{
		printf("\n\t[Data In File is corrupt (did not match current msd)]\n");
		return false;	
	}
	
	*current_msd += 1; //For some reason ( *current_msd++ ) does NOT work

	int elements_written = fwrite(current_msd, sizeof(int), 1, fp);

	//Testing retrived data
	if (elements_written != 1) 
	{
		printf("\n\t[Fwrite error]\n");
		return false;
	}

	return true;
}
