# [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## 題目
給一個遞增的陣列(可能會有重複的數字)，回傳開始與結束 `target` 的 `index`，如果陣列裡沒有 `target` 則回傳 `[-1, -1]` 

## 想法
一開始找最左邊 `target` 的 `index`，用 `flag` 紀錄最左邊已經找過，接下來只找最右邊。

## 程式碼
```python
class Solution:
    def binarySearch(self, nums: List[int], target: int, first: bool) -> int:
        left = 0
        right = len(nums)-1
        ans = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                ans = mid
                if first:
                    right = mid - 1
                else:
                    left = mid + 1
        return ans

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = True
        firstFound = self.binarySearch(nums, target, first)
        lastFound = self.binarySearch(nums, target, not first)
        return [firstFound, lastFound]
```

## 題目分類
`Binary Search`