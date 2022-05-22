# [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

## 問題
給一個整數 n，回傳陣列 n+1，其中要包含 [0,n] 的二進位表示中的 1 的數量
* Example 1
    ```
    n=2
    output:[0,1,1]
    explanation:
    0 -> 0 (number of 1s : 0)
    1 -> 1 (number of 1s : 1)
    2 -> 10 (number of 1s : 1)
    ```


## 想法
會發現一些規律，當變為奇數的時候，會是前一數字加一個1，偶數的話 dp[i] 與 dp[i/2] 的 1 數量不會變。(看以下例子)
* 2 -> 10
* 3 -> 11
* 4 -> 100
* 5 -> 101
* 6 -> 110
* 7 -> 111
* 8 -> 1000


## 程式碼
```cpp
vector<int> countBits(int n) {
    if(n==0) // 因為後面會宣告 dp[1] 所以預防 overflow 這邊直接回傳
        return {0};
    vector<int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<n+1; i++){
        if(i%2 == 0)
            dp[i] = dp[i/2];
        else
            dp[i] = dp[i-1] + 1;
    }
    return dp;
}
```
![](https://imgur.com/lW03zjg.png)
