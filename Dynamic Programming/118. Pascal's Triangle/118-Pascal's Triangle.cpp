#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows);

int main()
{
    int num;
    vector<vector<int> > dp;
    cin >> num;
    dp = generate(num);
    for(int i=0; i<num; i++){
        for(int j=0; j<dp[i].size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> generate(int numRows) {
    if(numRows == 1)
        return {{1}};
    vector<vector<int> > dp; // initialize
    int curRowSize;
    for(int i=0; i<numRows; i++){
        vector<int> tmp(i+1, 0); // 每一列為前一列大小加一
        dp.push_back(tmp);
    }
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<numRows; i++){
        curRowSize = dp[i].size();
        dp[i][0] = dp[i][curRowSize-1] = 1;
        for(int j=1; j<curRowSize-1; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; // 都是從上面兩個值而來(可以看題目給的圖形)
        }
    }
    return dp;
}
