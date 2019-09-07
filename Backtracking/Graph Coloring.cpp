#include <stdio.h>
#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c){
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

void graphColoring(bool graph[V][V], int m, int color[], int v){
    if (v == V){
        printSolution(color);
        return;
    }

    for (int c = 1; c <= m; c++){
        if (isSafe(v, graph, color, c)){
            color[v] = c;
            graphColoring(graph, m, color, v + 1);
            color[v] = 0;
        }
    }
}

void printSolution(int color[]){
    printf(" Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

int main(){
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; 
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    graphColoring(graph, m, color, 0);
    return 0;
}
