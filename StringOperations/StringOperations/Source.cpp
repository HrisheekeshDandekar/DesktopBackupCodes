/****************************| Without Pointers |**************************************
*
*	----  ||  RE-WRITING PRE DEFINED FUCNTIONS TO BE PERFOMED ON CHAR ARRAYS  ||  ----
* 
*	Fucntions:
*	Find Length of string
*	Reverse string
*	Concatinate two strings
*	Copy a string into another array
*	Compare two strings (If Deviation found, show the point of first occurance)
*	 
*			[ Oh and feel free to use spaces in inputs ^_^ ]
* 
*	-221018_Hrisheekesh Dandekar
* 
**************************************************************************************/


#include<iostream>
#include<string>

#define ARR_SIZE 100
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define underline "\033[4m"					/*Starts underlining (is a bit buggy after repeated calls)*/
#define RESETT   "\033[0m"					/*Resets output formats to Defaults*/

using namespace std;



int take_inputs_n_call(int function);
int check_length(char string[ARR_SIZE], int show_len);
int reverse_string(char string[ARR_SIZE]);
int concatinate(char string_1[ARR_SIZE], char string_2[ARR_SIZE]);
int copy(char string[ARR_SIZE], char string_2[ARR_SIZE]);
int compare(char string[ARR_SIZE], char string_2[ARR_SIZE]);
int repeat_function_call();


int main()
{
	repeat_function_call();			//In case one wishes to use a function without user interface
									//take_inputs_n_call(/*function number here*/) can be called
}

int repeat_function_call()		//Calls function again and again until prompted to stop
{

	char try_again = 0;
	while (((try_again == 'y') || (try_again == 'Y')) || (try_again == 0))			
	{
		int choice;
		cout << BOLDGREEN"\n\n==================================================================\n\n" RESETT;
		cout << BOLDMAGENTA "--|| " BOLDBLUE "Enter the choice for the operations you would like to do" BOLDMAGENTA " ||--\n\n" RESETT;
		cout << "\t( \033[1m\033[33m1\033[0m )  ------  \033[1m\033[36mlength check\033[0m\n\t( \033[1m\033[33m2\033[0m )  ------  \033[1m\033[36mreverse string\033[0m\n\t";
		cout << "( \033[1m\033[33m3\033[0m )  ------  \033[1m\033[36mconcatinate\033[0m\n\t( \033[1m\033[33m4\033[0m )  ------  \033[1m\033[36mcopy\033[0m\n\t( \033[1m\033[33m5\033[0m )  ------  \033[1m\033[36mcompare\033[0m\n";
		cout << BOLDGREEN"\n==================================================================\n\n\n" RESETT;
		cout << "Your Choice : " BOLDMAGENTA;
		cin >> choice;
		cout << RESETT;
		take_inputs_n_call(choice);
		cout << "\nWant to try again? (Enter Y for yes)\nChoice : " BOLDMAGENTA;
		cin >> try_again;
		cout << RESETT;
	}

	return 0;
}

int take_inputs_n_call(int function)
{
			//Creating arrays where inputs will be stored
	char string[ARR_SIZE];
	char string_2[ARR_SIZE];


	//Pointers to arrays first elements
	/*char* string;
	string = &string[0];
	
	char* string_2;
	string_2 = &string_2[0];*/


	
								
	switch (function) {
	case 1:						//Check Length
		cout << "\n\t\033[34m=======   \033[1m\033[31m: \033[1m\033[33mLENGTH CHECK \033[1m\033[31m:\033[0m\033[34m   =======\033[0m\n\n";
		cout << BOLDGREEN"Enter your string : " BOLDWHITE;
		getchar();							//Get char to clear the clipboard of the priv ENTER entered..
		cin.getline(string, ARR_SIZE);		//getline lets us take space as an input
		cout << RESETT;
		check_length(string, 1);
		break;
	case 2:						//String reversal
		cout << "\n\t\033[34m=======   \033[1m\033[31m: \033[1m\033[33mSTRING REVERSAL \033[1m\033[31m:\033[0m\033[34m   =======\033[0m\n\n";
		cout << BOLDGREEN"Enter your string : " BOLDWHITE;
		getchar();
		cin.getline(string, ARR_SIZE);
		reverse_string(string);
		break;
	case 3:						//Concatenate
		cout << "\n\t\033[34m=======   \033[1m\033[31m: \033[1m\033[33mCONCATINATE \033[1m\033[31m:\033[0m\033[34m   =======\033[0m\n\n";

		cout << BOLDGREEN"Enter your string1 : " BOLDWHITE;
		getchar();
		cin.getline(string, ARR_SIZE);
		cout << BOLDGREEN"\nEnter your string2 : " BOLDWHITE;
		cin.getline(string_2, ARR_SIZE);
		concatinate(string, string_2);
		break;
	case 4:						//Copy
		cout << "\n\t\033[34m=======   \033[1m\033[31m: \033[1m\033[33mCOPY \033[1m\033[31m:\033[0m\033[34m   =======\033[0m\n\n";
		cout << BOLDGREEN"Enter your string : " BOLDWHITE;
		getchar();
		cin.getline(string, ARR_SIZE);
		cout << RESETT;
		copy(string_2, string);
		break;
	case 5:						//compare
		cout << "\n\t\033[34m=======   \033[1m\033[31m: \033[1m\033[33mCOMPARE STRINGS \033[1m\033[31m:\033[0m\033[34m   =======\033[0m\n\n";
		cout << BOLDGREEN"Enter your string1 : " BOLDWHITE;
		getchar();
		cin.getline(string, ARR_SIZE);
		cout << BOLDGREEN"\nEnter your string2 : " BOLDWHITE;
		cin.getline(string_2, ARR_SIZE);
		cout << RESETT;
		compare(string, string_2);
		break;
	default:
		cout << "\nChoice entered not in range 1-5. Function will \033[1m\033[31mNOT\033[0m perform\n";
	}
	return 0;
}
int check_length(char string[ARR_SIZE],int show_len)
{
	int i = 0;
	for (i = 0; string[i] != '\0'; ++i);		//Loop Runs and increments i by 1 till \0 is found
	if (show_len == 1)//show_len variable set to one when the length needs to be displayed and not just returned
	{
		cout << "\n\t\033[4m\033[1m\033[36mString Length\033[0m ---> \033[1m\033[31m" << i << endl;
		cout << RESETT;
	}
	return i;
}
int reverse_string(char string[ARR_SIZE])
{
	int str_len = check_length(string, 0);
	char temp;
	for (int i = 0; i < (str_len) / 2; i++)	//We do not need to iterate through all the elements as
	{										//Swapping half of them with the other half reverses the string
		temp = string[i];
		string[i] = string[str_len - 1 - i];
		string[str_len - 1 - i] = temp;
	}
	cout << "\n\t\033[4m\033[1m\033[36mReversed String\033[0m ---> " BOLDYELLOW << string<<endl;
	cout << RESETT;

	return 0;
}
int concatinate(char string[ARR_SIZE], char string_2[ARR_SIZE])
{
	int string1_len = check_length(string, 0);
	int string2_len = check_length(string_2, 0);
	int str1_pos = string1_len;	//Just a variable to take the counter forward (Imm sure there are better methods)
	//Not using string1_len as to keep it available for future updates where another functionality was added
	for (int i = 0; i < string2_len; i++)		
	{
		string[str1_pos] = string_2[i];			
		str1_pos++;
	}
	string[str1_pos] = '\0';	//Marking the end of the string
	cout << "\n\t\033[4m\033[1m\033[36mAfter Concatenating \033[0m ---> " BOLDYELLOW << string << endl;
	cout << RESETT;
	return 0;

}
int copy(char *string, char *string_2)		
{
	int str2_len = check_length(string_2, 0);

	for (int i = 0; i < str2_len; i++)		//Copying contents as they are in the second array
	{
		string[i] = string_2[i];
	}
	string[str2_len] = '\0';
	cout << "\nString was copied and pasted in diffrent array.";
	cout<< "\n\n\t\033[4m\033[1m\033[36mString in new array \033[0m---> " BOLDYELLOW<< string;
	cout << RESETT"\n";
	return 0;
}
int compare(char string[ARR_SIZE], char string_2[ARR_SIZE])
{
	/*
	* Went a little over board. Here it shows where the first occurance of diffrance is in two strings 
	* Also their positions. If the strings have same letters but diff lengths (s1:1234 , s2:12345) then
	* it shows the last elements of the two strings. They might be same but you are aldready informed the strings
	* arent so i didnt bother writing another case
 	*/

	int str1_len = check_length(string, 0);
	int str2_len = check_length(string_2, 0);
	char check_further = 0;
	int unequal = 0;
	if (str1_len != str2_len)
	{
		
		cout << "\nStrings are \033[1m\033[31m\033[4mUNEQUAL\033[0m in size. Further checks not deployed\n\n";
		cout << BOLDBLUE"Would you like to see the first instance where strings dont match? (Y=yes) (N=no)\033[1m\033[33m\nChoice : ";
		cout << BOLDMAGENTA;
		cin >> check_further;
		cout << RESETT;
		if ((check_further != 'Y' && check_further != 'y'))
		{
			return 0;
		}
		unequal = 1;
	}
	
	int i = 0;
	int not_same = 0;
	for (i = 0; i < str1_len; i++)
	{
		if (string[i] != string_2[i])
		{
		not_same = 1;
			break;
		}
	}
	if ((not_same == 1)||(unequal==1))
	{
		if (unequal == 1)
		{
			int max_len;
			if (str1_len > str2_len)
			{
				max_len = str1_len;
			}
			else
			{
				max_len = str2_len;
			}

			cout << "\nStrings are  \033[1m\033[31m\033[4mUNEQUAL\033[0m, Deviation found at position [ " BOLDYELLOW << i + 1 << RESETT " ]";
			cout << BOLDBLUE"\n\nString 1 character position [ " BOLDMAGENTA << i + 1 << BOLDBLUE " ] ---> " BOLDRED << string[i] << RESETT;
			cout << BOLDBLUE"\nString 2 character position [ " BOLDMAGENTA << i + 1 << BOLDBLUE " ] ---> " BOLDRED << string_2[i] << RESETT << endl<<endl;

		}
		else
		{
			cout << "\nStrings are  \033[1m\033[31m\033[4mUNEQUAL\033[0m, Deviation found at position [ " BOLDYELLOW << i + 1 << RESETT " ]";
			cout << BOLDBLUE"\n\nString 1 character position [ " BOLDMAGENTA << i + 1 << BOLDBLUE " ] ---> " BOLDRED << string[i] << RESETT;
			cout << BOLDBLUE"\nString 2 character position [ " BOLDMAGENTA << i + 1 << BOLDBLUE " ] ---> " BOLDRED << string_2[i] << RESETT << endl;
		}
	}
	else
	{
		cout << "\n\nStrings are \033[4m\033[1m\033[32mIDENTICAL\033[0m\n";
	}
	return 0;
}