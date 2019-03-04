#include<iostream>
#include<conio.h>
#include<list>
using namespace std;
class Graph{
	public:
	 int v;
	 list<int> *ad;
	 Graph(int x){
	 	this->v=x;
	 	ad = new list<int>[x];
	 }
	 void addEdge(int u,int w){
	 	ad[u].push_back(w);
	 }
	 bool isReach(int m,int n){
	 	if(m==n){
	 		return true;
		 }
		bool *visit = new bool[v];
		for(int i=0;i<v;i++){
			visit[v]=false;
		}
		list<int>queue;
		visit[m]=true;
		queue.push_back(m);
		list<int>::iterator i;
		while(!queue.empty()){
			m = queue.front();
			queue.pop_front();
			for(i=ad[m].begin();i!=ad[m].end();i++){
				if(*i==n){
					return true;
				}
				if(!visit[*i]){
					visit[*i]=true;
					queue.push_back(*i);
				}
			}
		}
	 return false;
	 }
};
int main(){
 Graph *g=new Graph(4);
 g->addEdge(0,1);
 g->addEdge(0,2);
 g->addEdge(0,1);
 g->addEdge(1,2);
 g->addEdge(2,3);
 g->addEdge(3,0);
 int l=1,k=3;
 if(g->isReach(1,3)){
 	cout<<"The is a path b/w "<<l<<" and "<<k;
 }
 else{
 	cout<<"There is no path b/w "<<l<<" and "<<k;
 }
 return 0;
}

