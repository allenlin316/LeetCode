# [680-Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)

## 題目
給一字串，判斷是不是回文，最多可以刪掉一個字元

## 想法
因為最多只能刪掉一個字元，用兩指針一個從最左邊；一個從最右邊，如果不一樣就可能會是右邊指針指的字元刪掉繼續往下一隔跟左指針比，另一種可能是左邊指針指的字元刪掉繼續往下一隔跟右指針比。


## 程式碼
```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        // abbca¡Babca¡Babbcca¡Babc
        // "ebcbbececabbacecbbcbe" = ebcbbcecabbacecebbcbe
        int left=0, right=s.size()-1;
        while(left<right){
            if(s[left] != s[right]){
                return (isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1));
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right])    return false;
            left++;
            right--;
        }
        return true;
    }
};
```

![](https://imgur.com/gVWUf1t.png)

## 分類
`Two Pointers`、`Greedy`