# [744-Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)  

![](https://img.shields.io/badge/Level-Easy-green)

## 題目
給定一個字元陣列，回傳大於 `target` 的字元，如果沒有則回傳陣列的第一個字元。

## 程式碼
```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left = 0
        right = len(letters)-1
        res = 0
        while left <= right:
            mid = (left + right) // 2
            if letters[mid] <= target:
                left = mid + 1
            elif letters[mid] > target:
                res = mid
                right = mid - 1
        return letters[res]
```

## 題目分類
`Binary Search`