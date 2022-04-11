# [942-DI String Match](https://leetcode.com/problems/di-string-match/)

## 題目
一個排列組合 `perm` 有 `n+1` 個數字，由 `[0,n]` 組成。這個可以由長度為 `n` 的字串 `s` 表示，規則如下:
* `s[i] == 'I' if perm[i] < perm[i + 1]`
* `s[i] == 'D' if perm[i] > perm[i + 1]`
給一個字串 `s` 按照字串給的做出排列組合，輸出最後結果，如果有很多個答案，回傳其中一個就可以
* Example 1
    ```
    Input: s = "IDID"
    Output: [0,4,1,3,2]
    ```
* Example 2
    ```
    Input: s = "III"
    Output: [0,1,2,3]
    ```
* Example 3
    ```
    Input: s = "DDI"
    Output: [3,2,0,1]
    ```

## 想法
透過範例可以找到規律，當是 `I` 的時候，因為後一個數字要比前一個大，所以從最小的數字開始放，這樣後面要放大於他的數字才不會找不到；當是 `D` 的時候，從最大的開始放。

## 程式碼
```cpp
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> nums(s.size()+1, 0);
        int left = 0, right = nums.size()-1, i=0;
        while(left <= right){
            if(s[i] == 'I') nums[i] = left++;
            else    nums[i] = right--;
            i++;
        }
        return nums;
    }
};
```

![](https://imgur.com/cyb27ef.png)

## 分類
`Two Pointers`、`Greedy`