# [1277. Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

## 想法
先考慮最小的 `square matrix(2*2)`，從 $2\times2$ 的矩陣右下角開始來想，如果他的周圍都是 1，代表可以組成一個 $2\times2$ 再加上他自己也可以組成一個 $1\times1$，所以我們更新這個右下角的矩陣值為 2，代表有兩種 square matrices 的可能。所以當我們把這個觀念套用到題目的矩陣時，就會衍伸出 `dp[i][j] = min(2*2周圍)+1`


## 程式碼
```cpp
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
```
![](https://i.imgur.com/dN2yGes.png)