# [1877-Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)

## 題目
給一個陣列長度為偶數，每個數字兩兩一對(一個數字只能組成一組)，回傳組完後的 `最大值` 的那一組的 `和`，但他們兩兩一組的時候要是最小的組(看範例比較好懂意思)
* Example 1
    ```
    Input: nums = [3,5,2,3]
    Output: 7
    Explanation: The elements can be paired up into pairs (3,3) and (5,2).
    The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
    ```
* Example 2
    ```
    Input: nums = [3,5,4,2,4,6]
    Output: 8
    Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
    The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
    ```

## 想法
因為要兩兩一組然後又要 `minimized maximum pair sum`，兩指針指在陣列兩端，每次都把兩端相加求 `pair sum`，再與 `maximum` 相比。

## 程式碼
```cpp
class Solution {
public:
        
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left=0, right = nums.size()-1, maximum=0;
        while(left < right){
            maximum = max(maximum, nums[left++] + nums[right--]);
        }
        return maximum;
    }
};
```

![](https://imgur.com/TCiaSF6.png)



## 分類
`Two Pointers`、`Greedy`