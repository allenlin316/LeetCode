# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

## 想法
利用動態規劃的想法，會發現當每個位置為終點的最大子序列都是基於前一位置的最佳子序列所算出，所以可以藉由跑一次陣列，計算自己若為終點與前一個所形成的子序列會不會比從自己開始當起點時還大


## 程式碼
```cpp
int maxSubArray(vector<int>& nums) {
    // dynamic-programming, Kadane Algo.
    int maximum = nums[0];
    for(int i=1; i<nums.size(); i++){
        nums[i] = max(nums[i], nums[i-1]+nums[i]);
        maximum = max(maximum, nums[i]);
    }
    return maximum;
}
```
![](https://imgur.com/YqPGAQg.png)