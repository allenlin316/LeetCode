# [198. House Robber]()

## 問題
有一個專業小偷，要想辦法偷最多錢又不能被抓到，假如小偷偷了連續兩間房子就會觸發警報。給定每一間房子所擁有的金額

## 想法
* 考慮是否偷第 i 戶
  * 假設第 i-1 戶 `沒有` 被偷，偷第 i 戶可以增加 nums[i]
  * 假設第 i-1 戶 `有` 被偷，金額不變(因為會觸發警報)
* dp[i] : 考慮至第 i 戶的最大金額


## 程式碼
```cpp
int rob(vector<int>& nums) {
    // dp[i] : 至第 i 戶最大金額
    if(nums.size() == 1) // only one house
        return nums[0];
    int dp[nums.size()];
    for(int i=0; i<nums.size(); i++)   dp[i] = 0; // initialize
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<nums.size(); i++){
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[nums.size()-1];
}
```

![](https://imgur.com/XTZWYPF.png)

