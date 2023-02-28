# [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)


## 想法
二元搜尋的部分跟 `33-Search in Rotated Sorted Array` 一樣。如果 `target` 與 `nums[mid]` 在同一邊就用基本版的二元搜尋，如果不同邊則要把 `mid` 往 `target` 靠近。最後會發現本題因為陣列的數字會重複，所以 `target` 與 `nums[mid]` 是否同邊的判斷式會有錯誤，但只要一開始把陣列的最後面與最前面相同的刪除就可以解決。

## 程式碼
```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        # 1 0 1 1 1
        # target = 0
        while len(nums)>1 and nums[0]==nums[-1]:
            nums.pop(-1)
        left = 0
        right = len(nums) - 1
        
            
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
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
        return False
```

## 題目分類
`Binary Search`