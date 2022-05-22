# [1395. Count Number of Teams](https://leetcode.com/problems/count-number-of-teams/)

## 問題
有 `n` 個士兵，每個士兵都有獨一無二的 `rating`，可以組成每組三人共幾組?
* 三人一組需要滿足以下條件
  * 數列必須為遞增或遞減
  * [ rating[i], rating[j], rating[k] ]`0 <= i < j < k < n`



## 想法
|DP|2|5|3|4|1|
|:---:|---|---|---|---|---|
|small_dp|0|1|1|2|0|
|large_dp|0|0|1|1|4|





## 程式碼
```cpp
int numTeams(vector<int>& rating) {
    // e.g.  [2,5,3,4,1]
    // large_dp[i] : rating[i] 的左邊數值大於 rating[i] 共有幾個
    // small_dp[i] : rating[i] 的左邊數值小於 rating[i] 共有幾個 
    int length = rating.size();
    int small_dp[length];
    int large_dp[length];
    for(int i=0; i<length; i++){small_dp[i] = large_dp[i] = 0;} // initialize
    int cnt=0;
    small_dp[0] = large_dp[0] = 0;
    for(int i=1; i<length; i++){
        for(int j=0; j<i; j++){
            if(rating[i] < rating[j]){
                cnt += large_dp[j]; // 代表可以組成一組遞減數列
                large_dp[i]++;
            }
            else{
                cnt += small_dp[j]; // 代表可以組成一組遞增數列
                small_dp[i]++;
            }
        }
    }
    return cnt;
}
```
![](https://imgur.com/0FB072w.png)