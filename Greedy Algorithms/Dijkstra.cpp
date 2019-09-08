#include <iostream>
#include <limits.h>

using namespace std;

class Graph{
public:
    int vertexNum;
    int **edges;
    Graph(const int V){
        this->edges = new int *[V];
        for (int i = 0; i < V; i++){
            edges[i] = new int[V];
        }
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                edges[i][j] = 0;
            }
        }
        this->vertexNum = V;
    }
    void addEdge(int src, int dst, int weight){
        this->edges[src][dst] = weight;
    }
};

int minDistance(int mdist[], bool vset[], int V){
    int minVal = INT_MAX, minInd = 0;
    for (int i = 0; i < V; i++){
        if (!vset[i] && (mdist[i] < minVal)){
            minVal = mdist[i];
            minInd = i;
        }
    }
    return minInd;
}

void print(int dist[], int V){
    cout << "\nVertex  Distance" << endl;
    for (int i = 0; i < V; i++){
        if (dist[i] < INT_MAX)
            cout << i << "\t" << dist[i] << endl;
        else
            cout << i << "\tINF" << endl;
    }
}

void Dijkstra(Graph graph, int src){
    int V = graph.vertexNum;
    int mdist[V]; 
    bool vset[V]; 
    for (int i = 0; i < V; i++){
        mdist[i] = INT_MAX;
        vset[i] = false;
    }
    mdist[src] = 0;
    
    for (int count = 0; count < V - 1; count++){
        int u = minDistance(mdist, vset, V);
        vset[u] = true;
        for (int v = 0; v < V; v++){
            if (!vset[v] && graph.edges[u][v] && mdist[u] + graph.edges[u][v] < mdist[v]){
                mdist[v] = mdist[u] + graph.edges[u][v];
            }
        }
    }
    print(mdist, V);
}

int main(){
    int V, E, gsrc;
    int src, dst, weight;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph G(V);
    for (int i = 0; i < E; i++){
        cout << "\nEdge " << i + 1 << "\nEnter source: ";
        cin >> src;
        cout << "Enter destination: ";
        cin >> dst;
        cout << "Enter weight: ";
        cin >> weight;

        if (src >= 0 && src < V && dst >= 0 && dst < V){
            G.addEdge(src, dst, weight);
        }
        else{
            cout << "source and/or destination out of bounds" << endl;
            i--;
            continue;
        }
    }
    cout << "\nEnter source:";
    cin >> gsrc;
    Dijkstra(G, gsrc);

    return 0;
}
