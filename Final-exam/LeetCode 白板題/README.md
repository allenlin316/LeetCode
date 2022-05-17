# LeetCode 287 - Find the Duplicate Number

> 詳細解說可以參考[我的影片](https://youtu.be/uQv9dYglKvE)與 [PPT](https://github.com/allenlin316/LeetCode/blob/main/Final-exam/LeetCode%20%E7%99%BD%E6%9D%BF%E9%A1%8C/LeetCode%E7%99%BD%E6%9D%BF%E9%A1%8C.pdf)

## Binary-search 解法
```cpp
class Solution {
public:
    // binary-search
    int findDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1, mid, cnt=0;
        while(left < right){
            cnt=0;
            mid = (left+right)/2;
            for(int i=0; i<nums.size(); i++){ // 算出有幾個數字小於等於 mid
                if(nums[i] <= mid) 
                    cnt++;
            }
            if(mid < cnt)   right = mid; // 代表重複的數會在 mid 左邊
            else    left = mid+1;
        }
        return right;
    }
};
```

## Floyd's Algo. 解法
```cpp
class Solution {
public:
    // Floyd's Algo 
    int findDuplicate(vector<int>& nums) {
        int hare=0, tortoise=0;         // 兔子與烏龜都從起點出發
        while(true){
            hare = nums[nums[hare]];    // 兔子每次都走兩步
            tortoise = nums[tortoise];  // 烏龜每次都走一步
            if(hare == tortoise)        // 相遇的時候
                break;
        }
        hare = tortoise;  tortoise=0;   // 兔子原地待命，烏龜回到起點 
        while(true){
            tortoise = nums[tortoise];  // 烏龜每次走一步
            hare = nums[hare];          // 兔子每次也只走一步
            if(tortoise == hare)        // 相遇的時候，代表為循環的起點
                break;
        }
        return tortoise;
    }
};
```