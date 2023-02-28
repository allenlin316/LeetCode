#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& board, int i, int j);
void solve(vector<vector<char>>& board);

int main()
{
    vector<vector<char>> board;
    string inputArr;
    char ch;
    while(getline(cin, inputArr)){
        if(inputArr == "")  break;
        stringstream ss;
        vector<char> chArr;
        ss << inputArr;
        while(ss >> ch){
            chArr.push_back(ch);
        }
        board.push_back(chArr);
    }
    solve(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

void dfs(vector<vector<char>>& board, int i, int j){
    board[i][j] = '!';
    if(j-1>=0 && board[i][j-1] == 'O')
        dfs(board, i, j-1);
    if(j+1<=board[i].size()-1 && board[i][j+1] == 'O')
        dfs(board, i, j+1);
    if(i-1>=0 && board[i-1][j] == 'O')
        dfs(board, i-1, j);
    if(i+1 <= board.size()-1 && board[i+1][j] == 'O')
        dfs(board, i+1, j);
}

void solve(vector<vector<char>>& board) {
    int row = board.size(), col = board[0].size();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(board[i][j] == 'O' && (i*j==0 || i == row-1 || j == col-1)){
                dfs(board, i, j);
            }
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(board[i][j] == 'O')  board[i][j] = 'X';
            if(board[i][j] == '!')  board[i][j] = 'O';
        }
    }
}
