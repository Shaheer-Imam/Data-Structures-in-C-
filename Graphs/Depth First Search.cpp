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
			ad = new list<int>[v];
		}
		void addEdge(int x,int w){
			ad[x].push_back(w);
		}
		void DFSTraversal(int u,bool visit[]){
			visit[u]=true;
			cout<<u<<" ";
			list<int>::iterator i;
			for(i = ad[u].begin() ; i!= ad[u].end() ; ++i){
				if(!visit[*i]){
					DFSTraversal(*i,visit);
				}
			}
		}
		void DFS(){
			bool *visit = new bool[v];
			for(int j=0;j<v;j++){
				visit[j]=false;
			}
			for(int j=0;j<v;j++){
				if(visit[j]==false)
				DFSTraversal(j,visit);
			}
		}
};
int main(){
 Graph *g = new Graph(4);
 g->addEdge(0,1);
 g->addEdge(0,2);
 g->addEdge(1,2);
 g->addEdge(2,0);
 g->addEdge(2,3);
 g->addEdge(3,3);
 g->DFS();
 return 0;
}

