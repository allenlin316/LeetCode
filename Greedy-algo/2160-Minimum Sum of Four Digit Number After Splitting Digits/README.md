# [2160-Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/)

## 題目
給定四位數的數字，把四位數拆成兩個二位數相加，怎麼拆兩個數加起來最小

## 想法
十位數字影響數字的大小比個位數大，所以找出四位數裡最小的兩個數字，分別放到兩個二位數的十進位上，剩下的個位數就隨便放，不影響

## 程式碼
```cpp=
class Solution {
public:
    int minimumSum(int num) {
        stringstream ss;
        vector<int> arr(4,0);
        int new1, new2, i=0;
        char digit;
        ss << num;
        while(ss >> digit){
            arr[i++] = digit-'0';
        }
        sort(arr.begin(), arr.end());
        return (arr[0]*10+arr[2] + arr[1]*10 + arr[3]);
    }
};
```
![](https://imgur.com/a/s1AekV7)


## 分類
`Greedy`