# [455-Assign Cookies](https://leetcode.com/problems/assign-cookies/)

## 題目
有一群小孩，每個小孩有自己的貪婪指數 `g[i]`，也就是吃幾塊餅乾才會滿足，還有一堆餅乾，每一個餅乾的大小為 `s[j]`，如果 `s[j] >= g[i]` 就會讓 `i` 這個小孩滿足。我們要求最多可以讓幾個小孩滿足


## 想法
對兩個陣列排序，雙指針指在兩個陣列的頭，如果 `s[j] >= g[i]` 就讓指針 `j` 與 `i` 往後加一，如果不是的話就 `j` 往後加一看更大的餅乾可不可以讓小孩滿足


## 程式碼
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0, i=0, j=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 1 2 3
        // 1 1
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
                j++;
               cnt++;
            }
            else
                j++;
        }
        return cnt;
    }
};
```

![](https://imgur.com/0oLI28k.png)


## 分類
`Greedy`