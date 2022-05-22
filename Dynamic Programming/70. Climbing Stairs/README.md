# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

## 問題
每次爬樓梯只能爬 1 或 2 步，有幾種爬到第 n 階的方法


## 想法
找尋規律，會發現爬到第 n 階的方法就是算爬到第 `n-1` 與爬到第 `n-2` 階的方法。可以想當 `n=3` 的時候，方法共有 `(1,1,1)、(2,1)、(1,2)`



## 程式碼
```cpp
int climbStairs(int n) {
    int steps[n+1];
    for(int i=0; i<=n; i++) steps[i]=0; // initialize
    steps[0] = steps[1] = 1; // zero and first steps both have only one way  
    for(int i=2; i<=n; i++){
        steps[i] = steps[i-1] + steps[i-2];
    }
    return steps[n];
}
```
![](https://imgur.com/Kc2sTil.png)

# 分類
`Dynamic Prormming`