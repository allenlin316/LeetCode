# [1029. Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/)

## 問題
一個公司要面試 `2n` 個人。給一個二維的成本陣列，`costs[i] = [aCosti, bCosti]`，代表第 `i` 個人飛去城市 `a` 的花費是 `aCosti`，飛去城市 `b` 的花費是 `bCosti`。算出剛好 `n` 個人去 `a` 城市與 `n` 個人去 `b` 城市所花費的最少金額是多少    

## 想法
因為題目已經把資料結構定成二維的 vector，所以我們利用一些 `STL` 的函數來處理，不能直接對陣列的某一個城市的 `cost` 做排序，因為不一定最小值就是去那個城市，而是要跟自己的另一個城市相比，看去哪一個城市是花費較少的。因此，我把每個人去 `a` 與 `b` 城市的花費做相減，全部人對這個值做排序，最後，前一半的人就是去 `a` 城市，後一半的人去 `b` 城市。


## 程式碼
```cpp
class Solution {
public:
    
    static bool mycompare(vector<int> aDiff, vector<int> bDiff){
        if(aDiff[2] < bDiff[2]) return true;
        return false;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        for(int i=0; i<costs.size(); i++)
            costs[i].push_back({costs[i][0] - costs[i][1]});
        sort(costs.begin(), costs.end(), mycompare);
        int length = costs.size(), min_cost=0;
        for(int i=0; i<length/2; i++)
            min_cost += costs[i][0];
        for(int i=length/2; i<length; i++)
            min_cost += costs[i][1];
        return min_cost;
    }
};
```

![](https://imgur.com/ZFwX4LH.png)

## 分類
`Greedy`、`Sorting`