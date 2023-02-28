#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// unfinished
void dfs(vector<vector<int>>& heights, vector<vector<int>> &ocean, int row, int col);
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);

int main()
{
    vector<vector<int>> heights;
    vector<vector<int>> res;
    string inputArr;
    int num;
    while(getline(cin, inputArr)){
        if(inputArr == "")  break;
        stringstream ss;
        ss << inputArr;
        vector<int> intArr;
        while(ss >> num)
            intArr.push_back(num);
        heights.push_back(intArr);
    }
    res = pacificAtlantic(heights);
}

void dfs(vector<vector<int>>& heights, vector<vector<int>> &ocean, int row, int col){
    ocean[row][col] = true;
    vector<vector<bool>
    if(row-1>=0 && ocean[row-1][col] >= ocean[row][col])
        dfs(heights, ocean, row-1, col);
    if(row+1<=ocean.size()-1 && ocean[row+1][col] >= ocean[row][col])
        dfs(ocean, row+1, col);
    if(col-1>=0 && ocean[row][col-1] >= ocean[row][col])
        dfs(ocean, row, col-1);
    if(col+1<=ocean[row].size()-1 && ocean[row][col+1] >= ocean[row][col+1])
        dfs(ocean, row, col+1);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int row = heights.size(), col = heights[0].size();
    vector<vector<bool>> pacific(row, vector<bool>(col));
    vector<vector<bool>> atlantic(row, vector<bool>(col));
    vector<vector<int>> ans;
    for(int i=0; i<row; i++){
        dfs(heights, pacific, i, 0);
        dfs(heights, atlantic, i, col-1);
    }
    for(int i=0; i<col; i++){
        dfs(heights, pacific, 0, i);
        dfs(heights, atlantic, col-1, i);
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(pacific[i][j] == atlantic[i][j])
                ans.push_back({i, j});
        }
    }
    return ans;
}
