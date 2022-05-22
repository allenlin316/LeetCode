#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int countSquares(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>>matrix;
    int num;
    string inputRow;
    while(getline(cin, inputRow)){
        if(inputRow == "")  break;
        stringstream ss;
         vector<int> row;
        ss << inputRow;
        while(ss >> num)
            row.push_back(num);
        matrix.push_back(row);
    }
    cout << countSquares(matrix);
}

int countSquares(vector<vector<int>>& matrix) {
    // e.g. 0 1 1 1
    //         1 1 1 1
    //         0 1 1 1
    vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(), 0));
    int cnt=0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            if(i==0 || j==0)        // 2D 陣列的第一列與第一行都維持原本的值
                dp[i][j] = matrix[i][j];
            else if(matrix[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]}) + 1;         // 看 dp[i][j] 的四周有沒有辦法組成更大的 square matrix  
            cnt += dp[i][j];       // 計算全部共有的 square matrices
        }
    }
    return cnt;
}
