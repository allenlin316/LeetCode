#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j);
int numIslands(vector<vector<char>>& grid);

int main()
{
    vector<vector<char>> grid;
    string inputArr;
    char ch;
    while(getline(cin, inputArr)){
        if(inputArr == "")  break;
        stringstream ss;
        ss << inputArr;
        vector<char> chArr;
        while(ss >> ch){
            chArr.push_back(ch);
        }
        grid.push_back(chArr);
    }
    cout << numIslands(grid);
}

void dfs(vector<vector<char>> &grid, int i, int j){
    grid[i][j] = '2';   //標記找過的點
    if(j-1>=0 && grid[i][j-1] == '1')
        dfs(grid, i, j-1);
    if(i-1>=0 && grid[i-1][j] == '1')
        dfs(grid, i-1, j);
    if(i+1<=grid.size()-1 && grid[i+1][j] == '1')
        dfs(grid, i+1, j);
    if(j+1 <= grid[i].size()-1 && grid[i][j+1] == '1')
        dfs(grid, i, j+1);
}

int numIslands(vector<vector<char>>& grid) {
    int cnt=0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == '1'){
                cnt++;
                dfs(grid, i, j); // 檢查周圍是不是有跟目前這塊連在一起，有的話就標記起來才不會重複算到
            }
        }
    }
    return cnt;
}
