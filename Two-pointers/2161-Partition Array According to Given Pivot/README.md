
# [2161. Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

## 題目
給定 `array` 以及 `pivot 值`，要排序成下列規則
* 所有數字小於 `pivot 值` 排在所有大於 `pivot 值` 前面
* 等於 `pivot 值` 排在小於跟大於之間
* 原本 `array` 對應的數字關係位置要一樣，例如: [9,12,5,10,14,3,10], pivot = 10，要變成 [9,5,3,10,10,12,14]，9 還是在 5 的前面，12 還是在 14 的前面
* Example 1
    ```
    Input: nums = [9,12,5,10,14,3,10], pivot = 10
    Output: [9,5,3,10,10,12,14]
    Explanation: 
    The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
    The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
    The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
    ```
* Example 2
    ```
    Input: nums = [-3,4,3,2], pivot = 2
    Output: [-3,2,4,3]
    Explanation: 
    The element -3 is less than the pivot so it is on the left side of the array.
    The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
    The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
    ```

## 想法
創一個新的 `result vector`，用左右指針存題目給的陣列，小的從前面開始放，大的從後面開始放。最後剩下等於 `pivot` 放到空的位置填滿。 

## 程式碼
```cpp=
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left = 0, right = nums.size()-1, i=0;
        vector<int> result(nums.size(), 0);
        while(left<right && i<nums.size()){
            if(nums[i]<pivot)    result[left++]=nums[i];
            if(nums[nums.size()-i-1]>pivot)   result[right--]=nums[nums.size()-i-1];
            i++;
        }
        for(int j=left; j<=right; j++)
            result[j] = pivot;

        return result;
    }
};
```

![](https://i.imgur.com/rjGcuIa.png)


## 分類
`Two Pointers`

###### tags: `LeetCode`
