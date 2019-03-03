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
		void addEdge(int u,int w){
			ad[u].push_back(w);
		}
		void BFS(int n){
			bool *visit = new bool[v];
			for(int j =0;j<v;j++){
				visit[j] = false;
			}
				list<int> queue;
				visit[n]=true;
				queue.push_back(n);
				list<int>::iterator i;
				while(!queue.empty()){
					n = queue.front();
					cout<<n<<" ";
					queue.pop_front();
					for(i = ad[n].begin(); i != ad[n].end(); ++i){
						if(!visit[*i]){
							visit[*i]=true;
							queue.push_back(*i);
						}
					}
				}
		}
};
int main(){
 Graph *g=new Graph(4);
 g->addEdge(0,1);
 g->addEdge(0,2);
 g->addEdge(1,2);
 g->addEdge(2,0);
 g->addEdge(2,3);
 g->addEdge(3,3);
 g->BFS(2);
 return 0;
}

