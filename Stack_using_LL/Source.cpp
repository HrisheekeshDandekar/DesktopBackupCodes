#include <iostream>
#include <string>

using namespace std;

struct Element
{
	char val;
	Element* next;
};

struct Stack				
{
	int tot_elements;
	Element* head;
	//Initializing values upon creation
	Stack() : tot_elements(0), head(nullptr) {};	 
};

struct Stack a_stack;

int push();
int pop();
int display_all();
int check_stack_underflow();
int check_stack_overflow();
int display_before_pop();
void take_inputs(Element* a_ele);


int main()
{

}

int push()
{
	check_stack_overflow();

	Element* temp = new Element;

	take_inputs(temp);
	temp->next = a_stack.head;
	a_stack.head = temp;

	return 0;
}

int pop()
{
	check_stack_underflow();
	Element* temp;
	return 0;
}

int display_all()
{
	return 0;
}

int check_stack_underflow()
{

	return 0;
}

int check_stack_overflow()
{

	return 0;
}

int display_before_pop()
{

	return 0;
}

void take_inputs(Element* a_ele)
{

}
