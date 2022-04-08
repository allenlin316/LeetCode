
# [611-Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/)

## 題目
給一串數字，計算總共有幾組符合三角形邊長的條件
* Example 1
    ```
    Input: nums = [2,2,3,4]
    Output: 3
    Explanation: Valid combinations are: 
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3
    ```
* Example 2
    ```
    Input: nums = [4,2,3,4]
    Output: 4
    ```

## 想法
三角形的兩邊之和要大於第三邊。先找出數字裡面最大的數當作第三邊，利用二元搜尋的概念把指針指在最前端跟最後端(最大數的前一個)，每次都挑剩下數裡面最大數與最小數作加總，然後檢查有沒有大於第三邊，沒有就把最小的往右一隔。

## 程式碼
```cpp=
class Solution {
public:
        
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size(), left, right, result=0;
        for(int i=length-1; i>=0; i--){
            left=0, right=i-1;
            while(left <= right){   // binary-search
                if(nums[left]+nums[right] > nums[i]){
                    result += (right-left); // 因為把左邊指針往右一直移到右指針前都一定符合兩邊之和大於第三邊
                    right--;
                }
                else
                    left++;
            }
        }
        return result;
    }
};
```

![](https://i.imgur.com/pmtv1hZ.png)



## 題目分類
`Binart Search`、`Greedy`、`Two Pointers`

###### tags: `LeetCode`