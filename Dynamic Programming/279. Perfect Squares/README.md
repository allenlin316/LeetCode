# [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)

## 想法
假如 `n=4` 答案會是 `1` 喔，只要所有組成 `n` 是完全平方數就好，利用到 DP 的概念。每一個 `dp[i]` 會是最少完全平方數組成 `i` 的數量，從頭開始跑把每個數值存起來，例如 `dp[1]=1` 代表組成 1 就只需要他自己，`dp[3]=3` 代表組成 3 需要 3 個 1。


## 程式碼
```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 100000); // initialize
        int minimum;
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                int remain = i-j*j;
                dp[i] = min(dp[i], dp[remain]+1);
            }
        }
        return dp[n];
    }
};
```
![](https://imgur.com/xKYanEY.png)