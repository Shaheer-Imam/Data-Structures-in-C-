#include <iostream>
#define N 4
using namespace std;
void printSolution(int board[N][N]){
    cout << "\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << "" << board[i][j];
        cout << "\n";
    }
}

bool isSafe(int board[N][N], int row, int col){
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQ(int board[N][N], int col){

    if (col >= N){
        printSolution(board);
        return;
    }

    for (int i = 0; i < N; i++){
        if (isSafe(board, i, col)){
            board[i][col] = 1;
            solveNQ(board, col + 1);
            board[i][col] = 0;
        }
    }
}

int main(){

    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    solveNQ(board, 0);
    return 0;
}
