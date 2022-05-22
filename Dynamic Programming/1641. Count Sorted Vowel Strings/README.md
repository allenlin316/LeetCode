# [1641. Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/)

## 問題
英文有 5 個母音，藉由這 5 個母音排列出各種字串，且要照著字母順序 (a、e、i、o、u)

* Exmple1
    ```
    Input: n = 1
    Output: 5
    Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
    ```
* Exmple2
    ```
    Input: n = 2
    Output: 15
    Explanation: The 15 sorted strings that consist of vowels only are
    ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
    Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
    ```



## 想法
|n/Vowels|a|e|i|o|u|
|:---:|---|---|---|---|---|
|n=1|1|1|1|1|1|
|n=2|5|4|3|2|1|
|n=3|15|10|6|3|1|
|n=4|35|20|10|4|1|

## 程式碼
```cpp
int total(int *dp){
    int cnt = 0;
    for(int i=0; i<5; i++)
        cnt += dp[i];
    return cnt;
}

int countVowelStrings(int n) {
    int cnt=0;
    int dp[n][5];
    // build table
    for(int i=0; i<5; i++)  dp[0][i] = 1; // 第一列為已知，都為 1 
    for(int j=0; j<n; j++)  dp[j][4] = 1; // 第 5 行為已知，都是 1
    for(int i=1; i<n; i++){ // 從右至左、上到下建 table
        for(int j=3; j>=0; j--){
            dp[i][j] = dp[i][j+1] + dp[i-1][j]; // 每一個值為右邊加上面
        }
    }
    return total(dp[n-1]); // 回傳最後一列的加總
}
```
![](https://imgur.com/wvVWD0M.png)