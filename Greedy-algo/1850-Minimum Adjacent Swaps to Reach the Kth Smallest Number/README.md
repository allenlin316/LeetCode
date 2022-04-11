# [1850-Minimum Adjacent Swaps to Reach the Kth Smallest Number](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/)

## 題目
給一個字串 `num` 代表一個數字，及一個 `k` 值。一個數字為 `wonderful` 如果排列組合後大於 `num`。題目給的字串 `num` 需要最少幾次的 `swap` 才能變為`num` 經過 `k` 次的排列組合後的數字
* For example, when `num = "5489355142"`:
  * The 1st smallest wonderful integer is `"5489355214"`.
  * The 2nd smallest wonderful integer is `"5489355241"`.
  * The 3rd smallest wonderful integer is `"5489355412"`.
  * The 4th smallest wonderful integer is `"5489355421"`.

* Example 1
    ```
    Input: num = "5489355142", k = 4
    Output: 2
    Explanation: The 4th smallest wonderful number is "5489355421". To get this number:
    - Swap index 7 with index 8: "5489355142" -> "5489355412"
    - Swap index 8 with index 9: "5489355412" -> "5489355421"
    ```
* Example 2
    ```
    Input: num = "11112", k = 4
    Output: 4
    Explanation: The 4th smallest wonderful number is "21111". To get this number:
    - Swap index 3 with index 4: "11112" -> "11121"
    - Swap index 2 with index 3: "11121" -> "11211"
    - Swap index 1 with index 2: "11211" -> "12111"
    - Swap index 0 with index 1: "12111" -> "21111"
    ```
* Example 3
    ```
    Input: num = "00123", k = 1
    Output: 1
    Explanation: The 1st smallest wonderful number is "00132". To get this number:
    - Swap index 3 with index 4: "00123" -> "00132"
    ```


## 想法
首先要知道 C++ 的函式庫中有一個函式為 `std::next_permutation()` 這個函式其實會自動幫你算出排列組合且每次新的排列組合都是比前一個大，所以利用這個做出第 `k` 次的排列組合，拿這個組合與原本的字串 `num` 比。 
從不一樣的 digit 開始往後找，一找到一樣的就開始往回 `swap`。

## 程式碼
```cpp
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string beforePerm = num;
        int cnt=0;
        while(k--)
            next_permutation(num.begin(), num.end());
        for(int i=0; i<num.size(); i++){
            if(num[i] != beforePerm[i]){
                int j = i+1;
                while(num[j] != beforePerm[i]){
                    j++;
                }
                while(j > i){
                    swap(num[j], num[j-1]);
                    j--;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
```

![](https://imgur.com/YZwZeUL.png)


## 分類
`Two Pointers`、`Greedy`