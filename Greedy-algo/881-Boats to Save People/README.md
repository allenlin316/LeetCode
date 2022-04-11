# [881-Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)

## 題目
給一個陣列有許多人，陣列的值代表 `people[i]` 的重量，有無限量的船，每艘船的最大可承受的重量為 `limit`，且每艘船只能最多載兩個人，請問最少需要幾艘船才能載完這些人。不會有人的重量大於 `limit`
* Example 1
    ```
    Input: people = [1,2], limit = 3
    Output: 1
    Explanation: 1 boat (1, 2)
    ```
* Example 2
    ```
    Input: people = [3,2,2,1], limit = 3
    Output: 3
    Explanation: 3 boats (1, 2), (2) and (3)
    ```
* Example 3
    ```
    Input: people = [3,5,3,4], limit = 5
    Output: 4
    Explanation: 4 boats (3), (3), (4), (5)
    ```

## 想法
要達到最少船，代表每次載都要盡量載滿兩個人，也就是說要盡量塞滿每一艘船。我用兩個指針分別指到陣列的兩端，每次都兩個一組看會不會超過重量，超過就最重的先自己坐一艘，然後右指針往前進(往重量輕的)與左指針(重量輕的)再組看看，重複直到跑完。出迴圈後如果兩個指針指在相同位置代表剩一個人，就自己坐一艘。



## 程式碼
```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left=0, right=people.size()-1, boat=0;
        while(left < right){
            if(people[left] + people[right] <= limit){
                right--;
                left++;
                boat++;
            }
            else{
                right--;
                boat++;
            }
        }
        if(left == right)   boat++;
        return boat;
    }
};
```

![](https://imgur.com/S4unj0c.png)

## 分類
`Two Pointers`、`Greedy`