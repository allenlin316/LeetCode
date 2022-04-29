# [2148. Count Elements With Strictly Smaller and Greater Elements](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/)

## 問題
給定一列數字，請算出其中有多少個數字，在數列中同時有比他大與比他小的數


## 想法
其實這題可以直接硬爆，直接遍歷整個陣列，與頭與尾相比沒有等於就加加。第二個方法可以利用雙指針剛開始指在陣列兩端，遍歷陣列如果值一樣就指針往後/前。


## 程式碼
```cpp
class Solution {
public:
    int countElements(vector<int>& nums){
        int left=0, right=nums.size()-1, cnt=0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[left])
                break;
            left++;
        }
        // 2 7 11 15
        for(int i=nums.size()-2; i>0; i--){
            if(nums[i] != nums[right])
                break;
            right--;
        }
        for(int i=left+1; i<right; i++)
            cnt++;
        return cnt;
    }
};
```

![](https://imgur.com/9FPfkrC.png)


## 分類
`Array`、`Sorting`