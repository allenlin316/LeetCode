# [1855. Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)

## 題目
給定兩個 `non-increasing 0-indexed` 陣列: `nums1` 與 `nums2`
* 一對 `(i,j), where 0<=i<nums1.length and 0<=j<nums2.length` 是合格的如果以下兩個條件符合
  * `i <= j`
  * `nums1[i] <= nums2[j]`  

`(i,j)` 的距離為 `j-i`。請問最大距離為多少，如果沒有合格的 `pair` 回傳 `0`。  
> 注意:  An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length

* Example 1
    ```
    Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
    Output: 2
    Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
    The maximum distance is 2 with pair (2,4).
    ```
* Example 2
    ```
    Input: nums1 = [2,2,2], nums2 = [10,10,1]
    Output: 1
    Explanation: The valid pairs are (0,0), (0,1), and (1,1).
    The maximum distance is 1 with pair (0,1).
    ```
* Example 3
    ```
    Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
    Output: 2
    Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
    The maximum distance is 2 with pair (2,4).
    ```

## 想法
如果用線性解硬爆會 `TLE`，所以每次挑一個 `nums1` 的值當 `target`，二元搜尋 `nums2` 裡面有沒有符合條件的 `j` 值，有的話先存起來，往後找看看有沒有更大的，沒有的話代表 `j` 數值太小，變成往前找(因為陣列是以 `non-increasing` 排序的)


## 程式碼
```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maximum = 0, left=0, right=nums2.size()-1, mid;
        for(int i=0; i<nums1.size(); i++){
            if(maximum >= nums2.size()-1-i)   break;    // 代表我的 maximum 已經超越當下的最大可能，就沒有必要繼續找了
            left = i;
            right = nums2.size()-1;
            while(left <= right){
                mid = (left+right) / 2;
                if(nums1[i] > nums2[mid])
                    right = mid-1;
                else{
                    maximum = max(maximum, mid - i);
                    left = mid+1;
                }
            }
        }
        return maximum;
    }
};
```

![](https://imgur.com/JLAJYTK.png)


## 分類
`Two Pointers`、`Greedy`、`Binary Search`