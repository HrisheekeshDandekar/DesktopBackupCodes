#include <iostream>
using namespace std;

void push();
void pop();
void display();
int Empty();
int uppermostofstack();

struct Node{
    float info;
    Node*next;
};
struct Node*uppermost;


int main() {
    // Instructions
    cout << endl << " To add element: press 0 \n To remove an element: press 1\n To print all elements: press 2\n Repeat 0,1,2 to continue operations" << endl;
    int response = 3;
    while (true) {
        cin >> response;
        if (response == 0)
            push();
        else if (response == 1)
            pop();
        else if (response == 2)
            display();
    }
    return 0;
}




void push(){        // Pop an element in the stack
    cout << endl <<"\n Enter a new Element:";
    float info;
    cin >> info;
    
    struct Node* temp;       // To create a node 
    temp = new Node();

    
    if (!temp) {         // If memory could not be not allocated   
        cout << endl << "Stack Overflow";
    }


    temp->info = info;

    temp->next = uppermost;

    uppermost = temp;
}

void pop(){         // Last in first out, pop the last element
    struct Node* temp;

    if (uppermost==NULL) {      // If stack is empty
        cout << endl <<"Nothing in Stack" << endl;
    }

    else{
        temp = uppermost;
        uppermost = uppermost->next;
        temp->next = NULL;
        cout << endl << " uppermostmost Element: " << temp->info << endl;
        free(temp);
    }
}


void display(){     // To print the entire Stack
    struct Node*temp;
   
    if (uppermost==NULL)  {                       // If the stack is empty
        cout <<"\n Nothing in Stack \n";
    }

    else{
        temp= uppermost;
        while (temp!= NULL) {

            cout<<temp->info << "  ";
            temp=temp->next;
        }
    }
}


int Empty(){                    // If Stack is Empty
    return uppermost == NULL;
}


int uppermostofstack(){         // Go to the uppermost of stack
    
    if (!Empty())       // If stack is empty
        return uppermost->info;
}