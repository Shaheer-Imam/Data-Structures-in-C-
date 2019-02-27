#include<iostream>
#include<stdio.h>
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
class LinkedList{
	public:
		Node *head;
		LinkedList(){
			head=NULL;
		}
		void insertAtHead(int x){
			Node *n1=new Node(x);
			if(head==NULL){
				head=n1;
			}
			else{
				n1->next=head;
				head=n1;
			}
		}
		void insertAtEnd(int a){
			Node *n2=new Node(a);
			Node *current=head;
			if(head==NULL){
				head=n2;
			}
			else{
			 while(current->next!=NULL){
			 current=current->next;
		     }
			current->next=n2;
		}
		}
		void insertAtLocation(int y,int p){
			int i,counter=0;
			Node *current=head;
			Node *n3=new Node(y);
			Node *temp;
			while(current->next!=NULL){
				current=current->next;
				counter++;
			}
			if(p==1){
				if(head==NULL){
					head=n3;
				}
				else{
					n3->next=head;
					head=n3;
				}
			}
			else if(p>1 && p<=counter){
				current=head;
				for(i=1;i<p;i++){
					temp=current;
					current=current->next;
				}
				temp->next=n3;
				n3->next=current;
			}
			else{
				cout<<"Position out of range";
			}
		}
		void print(){
			system("cls");
			if(head==NULL){
				cout<<"The List is empty"<<endl;
			}
			else{
				Node *current=head;
				while(current!=NULL){
					cout<<"Node contains : "<<current->data<<endl;
					current=current->next;
				}
			}
			cout<<"\n\n";
		}
		void sort(){
			Node *current=head;
			Node *iterator;
			int val;
			if(head==NULL){
				cout<<"The list is empty!";
			}
			else{
				while(current->next!=NULL){
					for(iterator=current->next;iterator!=NULL;iterator=iterator->next){
						if(current->data > iterator->data){
							val = current->data;
							current->data = iterator->data;
							iterator->data = val;
						}	
					}
					current=current->next;
				}
			}
			system("cls");
		}
};
int main(){
	LinkedList *l=new LinkedList();
	int i,value;
	while(1){
	cout<<"1. Insert a node at the Beginning"<<endl;
	cout<<"2. Insert a node at the last"<<endl;
	cout<<"3. Insert a node at a specific location"<<endl;
	cout<<"4. Traverse the nodes"<<endl;
	cout<<"5. Sort the nodes"<<endl;
	cout<<"6. Exit"<<endl;
	cin>>i;
	switch(i){
		case 1:
			system("cls");
			cout<<"Enter value of node : ";
			cin>>value;
			l->insertAtHead(value);
			break;
		case 2:
			system("cls");
			cout<<"Enter value of node : ";
			cin>>value;
			l->insertAtEnd(value);
			break;
		case 3:
			system("cls");
			int pos;
			cout<<"Enter value of node : ";
			cin>>value;
			cout<<"Enter location to be inserted";
			cin>>pos;
			l->insertAtLocation(value,pos);
			break;	
		case 4:
			l->print();
			break;
		case 5:
			l->sort();
			break;
		case 6:
			exit(0);
			break;
		default:
				cout<<"Invalid Entry!";
	}
}
	return 0;
}
