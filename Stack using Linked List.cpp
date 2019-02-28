#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node(int x){
		this->data=x;
		this->next=NULL;
	}
};
class Stack{
	public:
	Node *top;
	Stack(){
		top=NULL;
	}
	int push(int);
	void pop();
	void display();
};
Stack::push(int y){
	Node *n1 = new Node(y);
	top = n1;
}
void Stack::pop(){
	Node *temp;
	if(top == NULL){
		cout<<"The stack is empty !\n\n";
	}
	temp = top;
	top = top->next;
	delete temp;
}
void Stack::display(){
	Node *current = top;
	while(current!=NULL){
		cout<<current->data<<"\n";
		current = current->next;
	}
}
int main(){
 Stack s;
 int value,choice;
 cout<<"1. Push ";
 cout<<"2. Pop ";
 cout<<"3. Display ";
 cout<<"4. Exit ";
 cin>>choice;
 switch(choice){
 	case 1:
 		cout<<"Enter value to be inserted : ";
 		cin>>value;
 		s.push(value);
 		break;
 	case 2:
 		s.pop();
 		break;
 	case 3:
 		s.display();
 		break;
 	case 4:
 		exit(0);
 	default:
 		cout<<"Invalid choice";
 }
 return 0;
}

