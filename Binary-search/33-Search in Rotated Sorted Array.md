# [33-Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## 題目
給一個經過 rotate 陣列，回傳 `target` 的 index 值，如果 `target` 不在陣列裡則回傳 `-1`。  

## 想法
分成左右兩邊子陣列分別做二元搜尋

##　程式碼
```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            # target and nums[mid] are at left portion array
            if (nums[mid] >= nums[0]) == (target >= nums[0]):
                if target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # target is at left portion, but nums[mid] is at right
            elif target >= nums[0]:
                right = mid - 1 # so mid has to get closer to left portion of array
            else:
                left = mid + 1
        return -1
```


## 題目分類
`Binary Search`