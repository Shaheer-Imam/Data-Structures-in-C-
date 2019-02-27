#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
#define MAX 1000 
  class Stack { 
    int top; 
	public: 
     int a[MAX];   
     Stack(){ 
	 top = -1; 
	} 
    bool push(int x); 
    int pop(); 
    bool isEmpty(); 
}; 
bool Stack::push(int x){
    if (top >= (MAX-1)) 
    { 
        cout << "Stack Overflow\n\n"; 
        return false; 
    } 
    else
    { 
        a[++top] = x; 
        cout<<x <<" pushed into stack\n"; 
        return true; 
    } 
} 
int Stack::pop(){ 
    if (top < 0) 
    { 
        cout << "Stack Underflow\n\n"; 
        return 0; 
    } 
    else
    { 
        int x = a[top--]; 
        return x; 
    } 
} 
bool Stack::isEmpty() { 
    return (top < 0); 
} 
int main(){
 Stack st;
 int value,i;
 while(1){
 	cout<<"1. Push an element\n";
 	cout<<"2. Pop an element\n";
 	cout<<"3. Exit\n";
 	cin>>i;
	 switch(i){
 		case 1:
 			cout<<"Enter value to be pushed : ";
 			cin>>value;
 			st.push(value);
 			break;
 		case 2:
 			st.pop();
 			break;
 		case 3:
 			exit(0);
 		default:
 			cout<<"Invalid choice !";
	 }
 }
 return 0;
}

