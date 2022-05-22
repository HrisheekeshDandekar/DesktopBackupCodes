

/*
* A code to simulate buying cupcakes
* 15003_Hrisheekesh Dandekar
* 
* Features:
* Included an Log-In system
* Included a Tabular form for billing.
*/

#include<stdio.h>
#include"C:\Users\pc\source\repos\Console_menu_1.0\display_console_menu.h"
#pragma warning(disable : 4996)

int main()
{
	
	int log_in_check = 0, password = 15003, password_check=0,account_no=22010058,input_acc_no;			//Block to check the account
	char input_name[21];
	while (log_in_check==0)
	{
		printf("Hello\n");
		printf("Enter your name:\n");
		scanf_s("%21s",&input_name,21);
		printf("Welcome %s\n",input_name);
		printf("\n");
		printf("Enter your Account number\n");
		scanf_s("%d", &input_acc_no);
		printf("Enter your password\n");
		scanf_s("%d", &password_check);
		if ((password_check == password) && (account_no==input_acc_no))
		{
			printf("Credentials matched succesfully\n");
			log_in_check = 1;
		}
		else
		{
			printf("User name and password does not match, Please try again\n\n");
		}

	}


	int vanilla_quantity = 0, red_velvet_quantity = 0, peanut_butter = 0, chocolate_quantity = 0, counter1, counter = 1, input_verify;
	float total_price;


	printf("Welcome to Dandekar's CAKE SHOPEE\n\n");
	printf("Enter the flavour of cupcake you would like to select\n\n");
	while (counter != 0)  //Taking input from the customer for the choice and quantity of the items
	{
		printf("1.Vanilla Clasico (Rs\-50)\n2.Chocolate silk(Rs\-55)\n3.Peanut Butter Childhood(Rs\-72)\n4.Red Velver Elite(Rs\-80)\n\n");
		printf("In case you have entered a wrong amount, simply select the flavour again and enter the correct cost\n");
		printf("After having selected all the flavours you are famished for, Enter 0\n");
		scanf_s("%d", &counter1);
		switch (counter1)
		{
		case 1:
			input_verify = 0;

			while (input_verify == 0)
			{
				printf("\nYou have selected Vanilla Clasico\n");
				printf("Enter the quantity of your desired flavour\n");
				scanf_s("%d", &vanilla_quantity);
				if (vanilla_quantity < 0)
				{
					printf("\nIt would be hard to put a price on a negative quantity, please select again ^_^\n");
				}
				else
				{
					input_verify = 1;
				}
			}
			break;

		case 2:
			input_verify = 0;

			while (input_verify == 0)
			{
				printf("\nYou have selected Chocolate Silk\n");
				printf("Enter the quantity of your desired flavour\n");
				scanf_s("%d", &chocolate_quantity);
				if (chocolate_quantity < 0)
				{
					printf("\nIt would be hard to put a price on a negative quantity, please select again ^_^\n");
				}
				else
				{
					input_verify = 1;
				}
			}
			break;

		case 3:
			input_verify = 0;

			while (input_verify == 0)
			{
				printf("\nYou have selected Peanut Butter Childhood\n");
				printf("Enter the quantity of your desired flavour\n");
				scanf_s("%d", &peanut_butter);
				if (peanut_butter < 0)
				{
					printf("\nIt would be hard to put a price on a negative quantity, please select again ^_^\n");
				}
				else
				{
					input_verify = 1;
				}
			}
			break;

		case 4:
			input_verify = 0;

			while (input_verify == 0)
			{
				printf("\nYou have selected Red Velver Elite\n");
				printf("Enter the quantity of your desired flavour\n");
				scanf_s("%d", &red_velvet_quantity);
				if (red_velvet_quantity < 0)
				{
					printf("\nIt would be hard to put a price on a negative quantity, please select again ^_^\n");
				}
				else
				{
					input_verify = 1;
				}
			}
			break;

		case 0:
			counter = 0;
			printf("\nThank you for shopping with us, Here is your receipt\n");
			break;

		default:
			printf("Invalid Input, Please try again\n\n");
		}
	}

	//Calculating the total

	total_price = (vanilla_quantity * 50) + (chocolate_quantity * 55) + (peanut_butter * 72) + (red_velvet_quantity * 80);

	//Adding tax

	total_price = (total_price * 0.15) + total_price;

	struct menu_contents menu =					//Printing out the bill
	{
		.title = "DANDEKAR'S CAKE SHOPPEE",

		.item[0].item = "Vanilla Clasico",.item[0].attribute1 = "Rs 50",.item[0].attribute2 = "",		//Item 1
		.item[1].item = "Chocolate silk",.item[1].attribute1 = "Rs 55",.item[1].attribute2 = "",//.item[1].attribute_rightmost = "Quantity",		//Item 1
		.item[2].item = "Peanut Butter Childhood",.item[2].attribute1 = "Rs 72",.item[2].attribute2 = "",//.item[2].attribute_rightmost = "Quantity",		//Item 1
		.item[3].item = "Red Velvet Elite",.item[3].attribute1 = "Rs 80",.item[3].attribute2 = "",//.item[3].attribute_rightmost = "Quantity",		//Item 1
		.item[4].item = "Total ammount",.item[4].attribute1 = "",.item[4].attribute2 = "",//.item[4].attribute_rightmost = "Ammount",		//Item 1

	};
	sprintf(menu.item[0].attribute_rightmost, "%d", vanilla_quantity);
	sprintf(menu.item[1].attribute_rightmost, "%d", chocolate_quantity);
	sprintf(menu.item[2].attribute_rightmost, "%d", peanut_butter);
	sprintf(menu.item[3].attribute_rightmost, "%d", red_velvet_quantity);
	sprintf(menu.item[4].attribute_rightmost, "%f", total_price);

	//Calling the function to print the contents in a tabular format 
	display_console_menu(menu);


	return 0;
}




