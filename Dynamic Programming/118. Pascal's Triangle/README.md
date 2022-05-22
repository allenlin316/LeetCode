# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)


## 想法
其實可以從題目的 GIF 看出來規律，二維陣列宣告的時候每一列的大小從 1 開始到 numRows，規律是除了三角形外圍為 1 的，都可以從上面兩數值相加而得


## 程式碼
```cpp
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
```
![](https://i.imgur.com/hK0xVen.png)