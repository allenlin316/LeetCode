
# [1689. Partitioning Into Minimum Number Of Deci-Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

## 題目
給你一個十進位的 `字串`，你要用 deci-binary 去組起來，所謂 deci-binary 就是裡面只有 `0` 跟 `1`，第一個數字不能是 `0`。
* Example 1
    ```
    Input: n = "32"
    Output: 3
    Explanation: 10 + 11 + 11 = 32
    ```
* Example 2
    ```
    Input: n = "82734"
    Output: 8
    ```
* Example 3
    ```
    Input: n = "27346209830709182346"
    Output: 9
    ```

## 想法
其實我不知道我這樣算不算 Greedy，不過我就是從最大的數字 `9` 開始，每一次都看看字串裡面有沒有對應的數字。

## 程式碼
```cpp
class Solution {
public:
    int minPartitions(string n) {
        int result=0;
        char ch;
        for(int i=9; i>0; i--){
            ch = i+'0';
            result = n.find(ch);
            if(result != -1)
                break;
        }
        return n[result]-'0';
    }
};
```

![](https://i.imgur.com/ZEWPnX9.png)


## 分類
`Greedy`

###### tags: `LeetCode`