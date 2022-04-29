# [搜尋數的中間值](https://hackmd.io/@wang1234/rJ_YSBGNq#%E7%AC%AC%E4%BA%94%E9%A1%8C%EF%BC%9A%E6%90%9C%E5%B0%8B%E6%95%B8%E7%9A%84%E4%B8%AD%E9%96%93%E5%80%BC)

## 問題
這題是我們演算法老師自己出的題目，是拿 [LeetCode - 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) 這題來改的。給定一個排序好的數列，數列中的數字有可能重覆，給定一個要搜尋的數，請傳回在數列中該數的中間index值。例如：給定的數列為：1,2,3,3,3,4，當要搜尋3時 會回傳3，此為中間3的index值。若是要搜尋的數字不在數列中時，則回傳-1若是要搜尋的數字在數列中有偶數個時，則回傳-2若是要搜尋的數字在數列中有奇數個時，則回傳中間的index

## 想法
用兩個二元搜尋分別找到最左邊的 index 值與最右邊的 index 值，最後在判斷他們在陣列中是偶數個還是奇數個，如果是奇數個就把找到的兩個 index 值相加除以二就是中間的 index 值了


## 程式碼
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, target;
    vector<int> nums;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cin >> target;
    int left = 0, right=nums.size()-1, mid, left_most_index=-1, right_most_index=-1;
    while(left <= right){
        mid = (left+right) / 2;
        if(nums[mid] > target)
            right = mid-1;
        else if(nums[mid] < target)
            left = mid+1;
        else{
            left_most_index = mid;
            right = mid-1;
        }
    }
    left =0, right = nums.size()-1;
    while(left <= right){
        mid = (left+right) / 2;
        if(nums[mid] > target)
            right = mid-1;
        else if(nums[mid] < target)
            left = mid+1;
        else{
            right_most_index = mid;
            left = mid+1;
        }
    }
    if(left_most_index == right_most_index && left_most_index==-1)
        cout << -1;
    else if( (left_most_index + right_most_index)%2!=0)
        cout << -2;
    else
        cout << (left_most_index+right_most_index)/2;
}
```



## 分類
`Binary Search`