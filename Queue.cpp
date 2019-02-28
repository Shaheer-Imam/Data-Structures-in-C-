#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class queue{
    int queue1[5];
    int rear,front;
    public:
    queue(){
	rear=-1;
	front=-1;
	}
    void enQueue(int x){
	if(rear >  4){
     cout <<"queue over flow\n\n";
     front=rear=-1;
     return;
    }
    queue1[++rear]=x;
    cout <<"inserted " <<x<<"\n\n";
    }
    void deQueue(){
    if(front==rear){
     cout <<"queue under flow\n\n";
     return;
    }
     cout <<"deleted" <<queue1[++front]<<"\n\n";
    }
    void display(){
     if(rear==front){
      cout <<" queue empty\n\n";
       return;
    }
    for(int i=front+1;i<=rear;i++)
     cout <<" "<<queue1[i]<<" ";
    }
};
 
int main(){
      int ch;
      queue qu;
      while(1)
        {
              cout <<"1.EnQueue\n";
              cout <<"2.DeQueue\n";
              cout <<"3.Display\n";
              cout <<"4.Exit\n ";
              cin >> ch;
              switch(ch)
                {
                  case 1:    
				  	cout <<"enter the element";
                    cin >> ch;
                    qu.enQueue(ch);
                    break;
                  case 2:  
				  	qu.deQueue();  
					break;
                  case 3:  
				    qu.display();
					break;
                  case 4: 
				  	exit(0);
                  }
          }
return (0);
}
