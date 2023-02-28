# [986-Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/)

## 題目
題目給兩個 list，問兩個 list 彼此交疊的區域。

## 想法
兩個指針各指在 list 上，互相比較各自的 `start` 與 `end`，兩兩比較 `start` 較大的取出來，而 `end` 較小的取出來。一個一個慢慢往後比。注意的是區間 `[a,b], a<=b`。 

## 程式碼
```python
class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = j = 0 # i -> firstList index, j -> secondList index
        res_list = []
        while i < len(firstList) and j < len(secondList):
            # [a, b]
            a = max(firstList[i][0], secondList[j][0])
            b = min(firstList[i][1], secondList[j][1])
            if a <= b:
                res_list.append([a,b])
            if firstList[i][1] > secondList[j][1]:
                j += 1
            else:
                i += 1
        
        return res_list
```

## 題目分類
`Two Pointers`