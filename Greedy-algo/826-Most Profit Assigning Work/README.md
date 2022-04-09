# [826-Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/)

## 題目
給定三個陣列分別為每份工作難度、利潤、工人可負擔的難度。每個員工最多只能做一份工作，但是每個工作可以被許多人完成。
* Example 1
    ```
    Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
    Output: 100
    Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
    ```
* Example 2
    ```
    Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
    Output: 0
    ```


## 想法
* 第一個做法會 <font color="red">TLE</font> : 每次都重新檢查每個員工的最佳利潤。沒有對員工排序，每次都要全部重跑一遍。$Time\ Complexity : O(n^2)$
* 第二個做法 : 對員工排序，所以後一個員工的最大利潤一定會大於等於前一個員工。用 `maximum` 把最大值先記錄起來，如果後一個工人有更大值就再換掉 `maximum`。$Time \ Complexity: O(nlogn)$


## 程式碼
```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int total=0, maximum=0, j=0;
        vector<pair<int,int>> job;
        for(int i=0; i<profit.size(); i++)
            job.push_back(make_pair(difficulty[i], profit[i]));
        sort(job.begin(), job.end());
        sort(worker.begin(), worker.end());
        for(int i=0; i<worker.size(); i++){
            while(worker[i]>=job[j].first && j<job.size())
                maximum = max(maximum, job[j++].second);
            total += maximum;
        }
        return total;
    }
};
```

![](https://imgur.com/ajQdp2G.png)

## 分類
`Two Pointers`、`Binary Search`、`Greedy`