#include<iostream>
#include<conio.h>
#include<list>
#include<vector>
using namespace std;
class Graph{
	public:
		int v;
		list<int>*ad;
		Graph(int x){
			this->v=x;
			ad = new list<int>[v];
		}
		void addEdge(int x,int w){
			ad[x].push_back(w);
		}
		void DFSTraversal(int u,vector<bool>&visit){
			visit[u]=true;
			list<int>::iterator i;
			for(i=ad[u].begin() ; i!=ad[u].end() ; ++i){
				if(!visit[*i]){
					DFSTraversal(*i,visit);
				}
			}
		}
		int FindMother(){
			vector<bool> visit(v,false);
			int z=0;
			for(int i=0;i<v;i++){
				if(visit[i]==false){
					DFSTraversal(i,visit);
					z=i;
				}
			}
			fill(visit.begin(),visit.end(),false);
			DFSTraversal(z,visit);
			for(int i=0;i<v;i++){
				if(visit[i]==false){
					return -1;
				}
			}
			return z;
		}
};
int main(){
 Graph *g=new Graph(7);
 g->addEdge(0,1);
 g->addEdge(0,2);
 g->addEdge(1,3);
 g->addEdge(4,1);
 g->addEdge(6,4);
 g->addEdge(5,6);
 g->addEdge(5,2);
 g->addEdge(6,0);
 cout<<"The mother is : "<<g->FindMother();
  return 0;
}

