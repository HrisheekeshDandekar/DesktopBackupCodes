/* Conalskdjlaskdjaslkdstraints
 *    It has at least 6 characters and at most 20 characters.
 *    It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
 *    It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a..." is 
 *    strong assuming other conditions are met).

 * Return
 * Minimum number of steps to make password strong

 * In one step you can
 * Insert one character to password,
 * Delete one character from password, or
 * Replace one character of password with another character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Checked_info {
	bool conditions_met;
	int tot_faults;
	int* fault_locations;
} Checked_info;

int strongPasswordChecker (char* password);  //Shitty name not given by me ( sites default )
bool all_conditions_met (char* password);

int main() 
{
	char* password = "123 Dad Mom ./. ";
	if (!strongPasswordChecker(password))
	{
		printf("\n\n[PASSWORD IS STRONG]\n\n");
	}
	else
	{
		printf("\n\n[PASSWORD IS WEAK]\n\n");
	}
	return 0;
	
}

int strongPasswordChecker (char* password)
{
	//Memory Innitilization
	Checked_info checked_info = {
		checked_info.conditions_met = false,
		checked_info.tot_faults = 0,
		checked_info.fault_locations = NULL,
	};
	
	//Checking if all conditions are met
	if (all_conditions_met(password)) 
	{
		return 0;
	}
	
	//Find total steps neded to fix password strength
	return 69;
}

bool all_conditions_met (char* password)
{
	//It has at least 6 characters and at most 20 characters.
	if (strlen(password) < 6 || strlen(password) > 20) 
	{
		printf("\n\nStrlen : %d\n\n", strlen(password));
		return false; 
	}
	
   //It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
	bool uppercase = false;
	bool lowercase = false;
	bool digit     = false;

	for (int i = 0; i < strlen(password); i++) 
	{
		//Uppercase letters ascii range : 65 to 90
		if (uppercase == false) 
		{
			if (password[i] > 64 && password[i] < 91) 
			{
				uppercase = true;
			}
		}
		
		//Lowercase letters ascii range : 97 to 112
		if (lowercase == false) {
			if (password[i] > 96 && password[i] < 113) 
			{
				lowercase = true;
			}
		}

		//Digit character ascii range : 48 to 57
		if (digit == false) {
			if (password[i] > 47 && password[i] < 58) 
			{
				digit = true;
			}
		}
	}	

	if (!(uppercase && lowercase && digit))
	{
		return false;
	}

    //It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a...")
	for (int i = 0; i < strlen(password) - 2; i++) 
	{
		if (password[i] == password[i + 1] && password[i] == password[i + 2]) 
		{
			printf("\n\nrepeat chars at %d, (%c,%c,%c)\n\n", i+1, password[i], password[i+1], password[i+2]);
			return false;
		}
	}
	
	//Returns false if any one is false
	return true;
}