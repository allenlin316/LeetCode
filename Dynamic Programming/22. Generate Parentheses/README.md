# [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

## 想法
以下樹是以 n = 2 為例(可以點開比較清楚)，運用到 backtracking 的想法，其實就是遞迴解，當左括號小於 n，代表還可以繼續加左括號；當右括號小於左括號的數量就要補齊，結束條件為當括號的總數大於等於 n*2 就代表做完了(因為題目說要成對括號)
[![](https://i.imgur.com/bdkIihs.png)](https://i.imgur.com/bdkIihs.png)

## 程式碼
```cpp
class Solution {
public:
    void backTracking(vector<string> &res, string cur, int open, int close, int n){
        if(cur.size() >= n*2){
            res.push_back(cur);
            return;
        }

        if(open < n)
            backTracking(res, cur+"(", open+1, close, n);

        if(close < open)
            backTracking(res, cur+")", open, close+1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backTracking(res, "", 0, 0, n);
        return res;
    }
};
```
![](https://i.imgur.com/gP2S9Mk.png)