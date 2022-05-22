/*				---==== {Singly Linked List} ====---
*            __  __                                       
*			/ /_/ /\				       
*		   / __  / /                                          
*		  /_/ / / /                                             
*		  \_\/\_\/risheekesh  Dandekar
*
*			Roll : 221018
*			GR   : 22010058
*			Batch A1
*			Assignment 2							
* 
*		{ Features }
*			[ The whole list can be sorted according to its key ]
* 
*			[ Each Node has a unique key ]
*				(While Creating new node, same key cannot be repeated)
*				(While modifying , key can be left as it is)
*			
*			[ Modify/Insert/Delete element at position has 2 modes ]
*				(Mode 1 : Mentioned functions can be done with respect to nodes unique key)
*				(Mode 2 : Mentioned functions can be done with respect to the nodes position in the list)
* 
*			[ Clean menu style representation of the functions that can be performed ]
* 
*			[ Program behaves correctly no matter what when inputs are of expected type (int/string) ]
*			
*			[No memory leaks as all the inactive nodes are freed]
*			
*/
#include<iostream>
#include<string>

#define RESET_COLOUR cout<<"\033[1m\033[37m";

using namespace std;

struct Node
{
	string name;
	string department;
	int emp_id;
	int salary;
	Node* next = nullptr;
};

struct SLL				//[future task] add a counter to check the number of elements live in the list
{
	int elements_live  = 0;
	Node* head         = nullptr;
	Node* current      = nullptr;
};

struct SLL sll;

bool g_sll_exists = false;	//Keeping track of existence of SLL

int functions_menu_display();
int deploy_sll();
int insert_begin();
int create_sll();
int insert_begin();
int insert_end();
int insert_pos();
int delete_begin();
int delete_end();
int delete_pos();
int modify_pos();
int sort();
int swap_nodes(Node* tail, Node* iterator);
int search_node();
int display_list();
int nodes_to_create();
void take_inputs(Node* node, bool b_take_key_input);
bool key_uniqueness_pass(int proposed_key);
void operation_number_input_taken(int& choice);
bool input_validated(int choice);
int function_called(int choice, bool& exit_sll);
int show_before_deleting(Node* to_delete);


int WIDTH_VAL = 24;

int main()
{
	deploy_sll();
	return 0;
}



int deploy_sll()
{
	int choice = 0;
	bool exit_sll = false;

	while (exit_sll == false)
	{
		functions_menu_display();
		operation_number_input_taken(choice);
		if (input_validated(choice) == true)
		{
			function_called(choice, exit_sll);
		}
	}

	return 0;
}



int create_sll()
{
	cout << "\n\n\t----==== { \033[1m\033[37mCreate SLL function\033[0m } ====----\n";

	g_sll_exists = true;
	Node* temp;

	int starting_elements = nodes_to_create();

	temp = new Node;
	sll.head = temp;
	sll.current = temp;
	take_inputs(temp, true);

	for (int i = 0; i < starting_elements - 1; i++)
	{
		temp = new Node;
		take_inputs(temp, true);
		sll.current->next = temp;
		sll.current = temp;
	}


	return 0;
}

int insert_begin()
{
	cout << "\n\n\t----==== { \033[1m\033[32mInsert begin function\033[0m } ====----\n";
	
	int tot_nodes_to_create = nodes_to_create();

	for (int i = 0; i < tot_nodes_to_create; i++)
	{
		Node* temp = new Node;
		take_inputs(temp, true);
		temp->next = sll.head;
		sll.head = temp;
	}

	return 0;
}

int insert_end()
{
	cout << "\n\n\t----==== { \033[1m\033[32mInsert end function\033[0m } ====----\n";

	Node* iterator = sll.head;
	while (iterator->next != nullptr)	//Finding the last node in the SLL
		iterator = iterator->next;


	int tot_nodes_to_create = 0;
	while (tot_nodes_to_create < 1)
	{
		cout << "\nEnter the number of nodes you want to enter : ";
		cin >> tot_nodes_to_create;
		if (tot_nodes_to_create < 1)
		{
			cout << "\n[\033[1m\033[31m ERROR \033[0m] you cannot create nodes less than 1";
		}
	}

	for (int i = 0; i < tot_nodes_to_create; i++)
	{
		Node* new_element = new Node;
		take_inputs(new_element, true);
		iterator->next = new_element;
		iterator = new_element;
	}

	return 0;
}

int insert_pos()
{
	cout << "\n\n\t----==== { \033[1m\033[32mInsert at position function\033[0m } ====----\n";
	char c_choice = 0;

	while (c_choice != 'Y' && c_choice != 'y' && c_choice != 'N' && c_choice != 'n')
	{
		cout << "\nWould you like to Insert a node after a key? [Y/N] : ";
		getchar();		//Clearing out \0 in input buffer
		cin >> c_choice;

		if (c_choice != 'Y' && c_choice != 'y' && c_choice != 'N' && c_choice != 'n')
			cout << "\nEnter [Y] for yes or [N] for no";
	}

	Node* iterator = sll.head;
	int key;
	if (c_choice == 'Y' || c_choice == 'y')
	{
		cout << "\nEnter the key after which a node is to be inserted : ";
		cin >> key;
		
		while (iterator->emp_id != key)
		{
			if (iterator->next == nullptr)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] entered key was not found in the linked list";
				return 1;
			}
			iterator = iterator->next;
		}

		Node* new_node = new Node;
		take_inputs(new_node, true);
		new_node->next = iterator->next;
		iterator->next = new_node;

	}
	else
	{
		int insert_after = 0;
		int c_position   = 1;

		while (insert_after < 1)
		{
			cout << "\nEnter the position after which you would like to enter an element : ";
			cin >> insert_after;
			if (insert_after < 1)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] element positions start at 1. Please enter a number larger than 0";
			}
		}

		while (c_position != insert_after)
		{
			if (iterator->next == nullptr)
			{
				cout << "[\033[1m\033[31m ERROR \033[0m] position entered does not exist in the list";
				return 1;
			}
			iterator = iterator->next;
			c_position++;
		}

		Node* new_node = new Node;
		take_inputs(new_node, true);

		new_node->next = iterator->next;
		iterator->next = new_node;

	}
	return 0;
}

int delete_begin()
{
	cout << "\n\n\t----==== { \033[1m\033[35mDelete Begin function\033[0m } ====----\n";

	cout << "\033[1m\033[35m";
	if (sll.head->next != nullptr)
	{
		Node* temp = sll.head->next;
		show_before_deleting(sll.head);
		delete sll.head;
		sll.head = temp;
		cout << "\n\t~Element Deleted successfully~";
	}
	else
	{
		show_before_deleting(sll.head);
		delete sll.head;
		cout << "\n\t~Element Deleted successfully~";
		cout << "\n\t< WARNING > This was the last element in the SLL";
		g_sll_exists = false;
	}

	RESET_COLOUR

	return 0;
}

int delete_end()
{
	cout << "\n\n\t----==== { \033[1m\033[35mDelete End function\033[0m } ====----\n";

	cout << "\033[1m\033[35m";

	Node* iterator = sll.head;
	Node* new_end_node = nullptr;
	while (iterator->next != nullptr)
	{
		new_end_node = iterator;
		iterator = iterator->next;
	}

	if (sll.head != iterator)
	{
		Node* temp = sll.head->next;
		show_before_deleting(iterator);
		delete iterator;
		
		new_end_node->next = nullptr;
		cout << "\n\t~Element Deleted successfully~\n";

	}
	else
	{
		show_before_deleting(sll.head);
		delete sll.head;
		cout << "\t~Element Deleted successfully~";
		cout << "\n\t< WARNING > This was the last element in the SLL\n";
		g_sll_exists = false;
	}

	RESET_COLOUR
	return 0;
}

int delete_pos()
{
	cout << "\n\n\t----==== { \033[1m\033[35mDelete position function\033[0m } ====----\n";
	
	cout << "\033[1m\033[35m";

	char c_choice = 0;

	while (c_choice != 'Y' && c_choice != 'y' && c_choice != 'N' && c_choice != 'n')
	{
		cout << "\nWould you like to Delete a node at a key? [Y/N] : ";
		getchar();		//Clearing out \0 in input buffer
		cin >> c_choice;

		if (c_choice != 'Y' && c_choice != 'y' && c_choice != 'N' && c_choice != 'n')
			cout << "\nEnter [Y] for yes or [N] for no";
	}

	Node* iterator = sll.head;
	Node* following_iterator = nullptr;
	int key;
	if (c_choice == 'Y' || c_choice == 'y')
	{
		cout << "\nEnter the key of the node to be Deleted : ";
		cin >> key;

		if (sll.head->emp_id == key && sll.head->next == nullptr)
		{
			show_before_deleting(sll.head);
			delete sll.head;
			cout << "\t~Element Deleted successfully~";
			cout << "\n\t< WARNING > This was the last element in the SLL\n";
			g_sll_exists = false;

			return 0;
		}

		if (sll.head->emp_id == key)
		{
			Node* new_head = sll.head->next;
			show_before_deleting(sll.head);
			delete sll.head;
			cout << "\t~Element Deleted successfully~\n";
			sll.head = new_head;

			return 0;
		}

		while (iterator->emp_id != key)
		{
			if (iterator->next == nullptr)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] entered key was not found in the linked list";
				return 1;
			}
			following_iterator = iterator;
			iterator = iterator->next;
		}

		following_iterator->next = iterator->next;
		show_before_deleting(iterator);
		delete iterator;
		cout << "\t~Element Deleted successfully~\n";

	}
	else
	{
		int delete_at = 0;
		int c_position = 1;

		while (delete_at < 1)
		{
			cout << "\nEnter the position at which you would like to delete an element : ";
			cin >> delete_at;
			if (delete_at < 1)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] element positions start at 1. Please enter a number larger than 0";
			}
		}

		if (delete_at == 1 && sll.head->next == nullptr)
		{
			show_before_deleting(sll.head);
			delete sll.head;
			cout << "\t~Element Deleted successfully~";
			cout << "\n\t< WARNING > This was the last element in the SLL\n";
			g_sll_exists = false;
			return 0;
		}

		if (delete_at == 1)
		{
			Node* new_head;
			new_head = sll.head->next;

			show_before_deleting(sll.head);
			delete sll.head;
			cout << "\t~Element Deleted successfully~";

			sll.head = new_head;
			return 0;
		}

		Node* following_iterator = nullptr;
		while (c_position != delete_at)
		{
			if (iterator->next == nullptr)
			{
				cout << "[\033[1m\033[31m ERROR \033[0m] position entered does not exist in the list";
				return 1;
			}

			following_iterator = iterator;
			iterator = iterator->next;
			c_position++;
		}

		following_iterator->next = iterator->next;
		show_before_deleting(iterator);
		delete iterator;
		cout << "\t~Element Deleted successfully~";

	}
	
	RESET_COLOUR

	return 0;
}

int show_before_deleting(Node* to_delete)
{
	cout << "\n\t[Element to be deleted]";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\tEmployee id : " << to_delete->emp_id;
	cout << "\n\t- - - - - - - - - - - - - - - -\n";
	cout << "\tEmployee Name : " << to_delete->name;
	cout << "\n\t- - - - - - - - - - - - - - - -\n";
	cout << "\tEmployee Department : " << to_delete->department;
	cout << "\n\t- - - - - - - - - - - - - - - -\n";
	cout << "\tEmployee Salary : " << to_delete->salary;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return 0;
}

int modify_pos()
{
	cout << "\n\n\t----==== { \033[1m\033[33mModify Node function\033[0m } ====----\n";
	char c_choice = 0;

	while (c_choice != 'Y' && c_choice != 'y' && c_choice != 'N' && c_choice != 'n')
	{
		cout << "\nWould you like to Modify a node with a specific key? [Y/N] : ";
		getchar();		//Clearing out \0 in input buffer
		cin >> c_choice;

		if (c_choice != 'Y' && c_choice != 'y' && c_choice != 'N' && c_choice != 'n')
			cout << "\nEnter [Y] for yes or [N] for no";
	}

	Node* iterator = sll.head;
	int key;
	if (c_choice == 'Y' || c_choice == 'y')
	{
		cout << "\nEnter the key after which a node is to be modified : ";
		cin >> key;

		while (iterator->emp_id != key)
		{
			if (iterator->next == nullptr)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] no node with key ( " << key << " ) exists";
				return 0;
			}
			iterator = iterator->next;
		}
		int new_key;

		cout << "Enter employee id (key) for node : ";
		cin >> new_key;
		if (new_key == key)
		{
			take_inputs(iterator,false);
		}
		else
		{
			bool new_key_verified = false;
			while (new_key_verified == false)
			{
				new_key_verified = key_uniqueness_pass(new_key);
				if (new_key_verified == true)
				{
					iterator->emp_id = new_key;
					break;
				}
				else
				{
					cout << "Enter employee id (key) for node : ";
					cin >> new_key;
				}
			}
			take_inputs(iterator, false);
		}
		return 1;

	}
	else
	{
		int modify_at = 0;
		int c_position = 1;
		int new_key;

		while (modify_at < 1)
		{
			cout << "\nEnter the position at which you would like to modify node  : ";
			cin >> modify_at;
			if (modify_at < 1)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] element positions start at 1. Please enter a number larger than 0";
			}
		}

		while (c_position != modify_at)
		{
			if (iterator->next == nullptr)
			{
				cout << "[\033[1m\033[31m ERROR \033[0m] position entered does not exist in the list";
				return 1;
			}
			iterator = iterator->next;
			c_position++;
		}


		cout << "Enter employee id (key) for node : ";
		cin >> new_key;

		int key = iterator->emp_id;
		if (new_key == key)
		{
			take_inputs(iterator, false);
		}
		else
		{
			bool new_key_verified = false;
			while (new_key_verified == false)
			{
				new_key_verified = key_uniqueness_pass(new_key);
				if (new_key_verified == true)
				{
					iterator->emp_id = new_key;
					break;
				}
				else
				{
					cout << "Enter employee id (key) for node : ";
					cin >> new_key;
				}
			}
			take_inputs(iterator, false);
		}

	}
	return 0;
}

int sort()		//More or less, bubble sort (Inefficient because I am not actually swapping the elements)	
{
	cout << "\n\n\t----==== { \033[33mSort SLL function\033[0m } ====----\n";

	Node* tail              = sll.head;
	Node* iterator		    = sll.head->next;

		//Bubble sort like algorithm
	for (tail = sll.head; tail->next != nullptr; tail = tail->next)
		for (iterator = tail->next; iterator != nullptr; iterator = iterator->next)
			if (tail->emp_id > iterator->emp_id)
				swap_nodes(tail, iterator);		//Contents are being swapped, future plan to implement a proper swap


	cout << "\n[ \033[33mSUCCESS\033[0m ] Elements sorted successfully \n";
	char choice = 0;
	while (choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n')
	{
		cout << "\nWould you like to display the sorted list? [Y/N] : ";
		cin >> choice;
		if (choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n')
		{
			cout << "\n[ \033[1m\033[31mWRONG INPUT\033[0m ] Enter ( Y ) or ( y ) for YES";
			cout << "\n                Enter ( N ) or ( n ) for NO ";
		}
		else
		{
			display_list();
		}
	}

	return 0;
}

int swap_nodes(Node* tail, Node* iterator)	//Proper swap is possible but since the loops rely on the next address of elements,
{											// if elements are swapped, it becomes an infinite loop				
	Node temp;

	temp.emp_id = tail->emp_id;
	tail->emp_id = iterator->emp_id;
	iterator->emp_id = temp.emp_id;

	tail->name.swap(iterator->name);
	tail->department.swap(iterator->department);

	temp.salary = tail->salary;
	tail->salary = iterator->salary;
	iterator->salary = temp.salary;

	return 0;
}

int search_node()
{
	cout << "\n\n\t----==== { \033[1m\033[36mSearch Node function\033[0m } ====----\n";

	int search_id;
	Node* iterator = sll.head;
	cout << "\nEnter the id you want to look for : ";
	cin >> search_id;


	while (iterator != nullptr)
	{
		if (iterator->emp_id == search_id)
		{
			cout << "\n\033[1m\033[36m--------------==========  NODE FOUND  ==========--------------\n";
			cout << "\tEmployee id : " << iterator->emp_id;
			cout << "\n\t- - - - - - - - - - - - - - - -\n";
			cout << "\tEmployee Name : " << iterator->name;
			cout << "\n\t- - - - - - - - - - - - - - - -\n";
			cout << "\tEmployee Department : " << iterator->department;
			cout << "\n\t- - - - - - - - - - - - - - - -\n";
			cout << "\tEmployee Salary : " << iterator->salary;
			cout << "\n---------------------------------------------------------------\033[0m\n";
			return 0;
		}
		iterator = iterator->next;
	}
	
	
	
	cout << "\n\t[\033[1m\033[31m NOT FOUND! \033[0m]";
	cout << "\nNode with id : [ " << search_id << " ] does not exist\n";
	
	return 0;
}

int display_list()
{
	cout << "\n\n\t----==== { \033[1m\033[36mDisplay List function\033[0m } ====----\n";


	if (g_sll_exists == true)
	{
		Node* iterator = sll.head;
		while (iterator != nullptr)
		{
			cout << "\n---------------------------------------------------------------\n";
			cout << "\tEmployee id : " << iterator->emp_id;
			cout << "\n\t- - - - - - - - - - - - - - - -\n";
			cout << "\tEmployee Name : " << iterator->name;
			cout << "\n\t- - - - - - - - - - - - - - - -\n";
			cout << "\tEmployee Department : " << iterator->department;
			cout << "\n\t- - - - - - - - - - - - - - - -\n";
			cout << "\tEmployee Salary : " << iterator->salary;
			cout << "\n---------------------------------------------------------------\n";
			iterator = iterator->next;
		}
	}
	else
	{
		cout << "\n[\033[1m\033[31m ERROR \033[0m] List does not exist ";
	}
	return 0;
}

void take_inputs(Node* node, bool b_take_key_input)
{

	cout << "\n**************************************************************\n\n";


	if (b_take_key_input)
	{
		bool b_unique_key = false;
		while (!b_unique_key)		
		{
			int key;
			cout << "Enter employee id (key) for node : ";
			cin >> key;
			b_unique_key = key_uniqueness_pass(key);
			if (b_unique_key==false)
			{
				cout << "\n[\033[1m\033[31m ERROR \033[0m] This key is already in use\n";
			}
			else
			{
				node->emp_id = key;
			}
		}
	}


	cout << "\t- - - - - - - - - - - - - - - -\n";
	cout << "Enter name for employee [ "<<node->emp_id<<" ] : ";
	getchar();
	getline(cin, node->name);
	cout << "\t- - - - - - - - - - - - - - - -\n";
	cout << "Enter department for employee [ " << node->emp_id << " ] : ";
	getline(cin, node->department);
	cout << "\t- - - - - - - - - - - - - - - -\n";
	cout << "Enter salary for employee [ " << node->emp_id << " ] : ";
	cin >> node->salary;
	cout << "\n**************************************************************\n\n";

}

int nodes_to_create()
{
	int tot_nodes_to_create = 0;
	while (tot_nodes_to_create < 1)
	{
		cout << "\n Enter the number of nodes you want to fill: ";
		cin >> tot_nodes_to_create;
		if (tot_nodes_to_create < 1)
			cout << "\n\t[\033[1m\033[31m ERROR \033[0m] you cannot fill nodes less than one\n";
	}
	return tot_nodes_to_create;
}
	
bool key_uniqueness_pass(int proposed_key)
{
	Node* iterator = sll.head;

	
	while (iterator->next != nullptr)
	{
		if (iterator->emp_id == proposed_key)
		{
			return false;
		}
		iterator = iterator->next;
	}
	if (iterator->emp_id == proposed_key)
	{
		return false;
	}

	return true;
}

int functions_menu_display()
{
	//Just a visual display of menu of possible operations
	cout << "\n\t+\033[1m\033[34m=============================\033[0m+\n";
	cout << "\t|                             |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[37mCreate SLL           \033[0m";
	cout << "( \033[1m\033[37m1\033[0m )  |";
	cout << "\n\t| - - - - - - - - - - - - - - |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[32mInsert Begin         \033[0m";
	cout << "( \033[1m\033[32m2\033[0m )  |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[32mInsert End           \033[0m";
	cout << "( \033[1m\033[32m3\033[0m )  |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[32mInsert at Position   \033[0m";
	cout << "( \033[1m\033[32m4\033[0m )  |\n";
	//cout << "\t|                          |\n";
	cout << "\t| - - - - - - - - - - - - - - |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[35mDelete Begin         \033[0m";
	cout << "( \033[1m\033[35m5\033[0m )  |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[35mDelete End           \033[0m";
	cout << "( \033[1m\033[35m6\033[0m )  |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[35mDelete at Position   \033[0m";
	cout << "( \033[1m\033[35m7 \033[0m)  |\n";
	//cout << "\t|                          |\n";
	cout << "\t| - - - - - - - - - - - - - - |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[33mModify               \033[0m";
	cout << "( \033[1m\033[33m8\033[0m )  |\n";
	//cout << "|                          |\n";
	cout << "\t| - - - - - - - - - - - - - - |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[33mSort                 \033[0m";
	cout << "( \033[33m9\033[0m )  |\n";
	//cout <<\t "\t|                          |\n";
	cout << "\t| - - - - - - - - - - - - - - |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[36mSearch Node          \033[0m";
	cout << "( \033[1m\033[36m10\033[0m ) |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[36mDisplay List         \033[0m";
	cout << "( \033[1m\033[36m11\033[0m ) |\n";
	//cout <<\t "\t|                          |\n";
	cout << "\t| - - - - - - - - - - - - - - |\n";
	cout.width(WIDTH_VAL);
	cout << left << "\t| \033[1m\033[31mExit                 \033[0m";
	cout << "( \033[1m\033[31m12 \033[0m) |\n";
	cout << "\t|                             |\n";
	cout << "\t+\033[1m\033[34m=============================\033[0m+\n\n";


	return 0;

}

void operation_number_input_taken(int& choice)
{
	cout << "\nEnter operation Number : ";	//Might wanna spice up later ;)
	cin >> choice;
}

bool input_validated(int choice)
{
	if (choice < 1 || choice > 12)
	{
		cout << "\n\t[ Wrong input! ] available range of options (1-12) \n\n";
		return false;
	}
	else if (choice == 1 && g_sll_exists == true)
	{
		cout << "\n\t[\033[1m\033[31m ERROR \033[0m] SLL already exists \n";
		return false;
	}
	else if ((choice == 1 || choice == 12) || (g_sll_exists == true))
	{
		return true;
	}
	else
	{
		cout << "\n[\033[1m\033[31m ERROR \033[0m] SLL does not exist \n";
		return false;
	}
}
int function_called(int choice, bool& exit_sll)
{
	switch (choice)
	{
	case 1:
		g_sll_exists = true;
		create_sll();
		break;
	case 2:
		insert_begin();
		break;
	case 3:
		insert_end();
		break;
	case 4:
		insert_pos();
		break;
	case 5:
		delete_begin();
		break;
	case 6:
		delete_end();
		break;
	case 7:
		delete_pos();
		break;
	case 8:
		modify_pos();
		break;
	case 9:
		sort();
		break;
	case 10:
		search_node();
		break;
	case 11:
		display_list();
		break;
	case 12:
		cout << "\n\t+ ~~~~~~~~~~~~~~~~~~~~~~~~~ +";
		cout << "\n\t| [ SLL operations exited ] |";
		cout << "\n\t+ ~~~~~~~~~~~~~~~~~~~~~~~~~ +\n";
		cout << "\n\t[ ^_^ ]\n\n\n";
		exit_sll = true;
		break;
	}
	return 0;
}
