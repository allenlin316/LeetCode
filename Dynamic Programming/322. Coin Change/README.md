# [322. Coin Change](https://leetcode.com/problems/coin-change/)

## 想法
這題的 DP 架構跟 [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/) 很像，都從小的 basis 開始儲存起每個值。要換 `amount=2` 代表要從 `amount=1` 開始換起，而要換 `amount=1` 代表要換 `amount=0`，而 `dp[0]=0`。 就這樣慢慢建起 `DP` 的陣列。



## 程式碼
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                int remain = i - coins[j];
                if(remain >= 0)
                    dp[i] = min(dp[remain]+1, dp[i]);
            }
        }
        return (dp[amount] >= amount+1) ? -1 : dp[amount];
    }
};
```
![](https://imgur.com/UzPXocY.png)