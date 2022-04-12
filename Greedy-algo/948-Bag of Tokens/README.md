# [948. Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/)

## 題目
剛開始有初始 `power` 與 `score=0` 還有一堆的 `tokens`，每一個 token 的值為 `tokens[i]`。目標是要達到最高分(最高的 `score`)用以下兩種玩法
* 如果目前的 `power` 至少 `tokens[i]`，可以捨棄 `tokens[i]` 的 `power` 來獲得 `1 score`
* 如果目前 `score` 大於等於 `1`，捨棄 1 個 `score` 得到 `tokens[i]` 的 `power`
每個 token 只能被玩一次，但可以任何順序，不一定要每個 token 都玩，回傳最大可以得到的 `score`
* Example 1
    ```
    Input: tokens = [100], power = 50
    Output: 0
    Explanation: Playing the only token in the bag is impossible because you either have too little power or too little score.
    ```
* Example 2
    ```
    Input: tokens = [100,200], power = 150
    Output: 1
    Explanation: Play the 0th token (100) face up, your power becomes 50 and score becomes 1.
    There is no need to play the 1st token since you cannot play it face up to add to your score.
    ```
* Example 3
    ```
    Input: tokens = [100,200,300,400], power = 200
    Output: 2
    Explanation: Play the tokens in this order to get a score of 2:
    1. Play the 0th token (100) face up, your power becomes 100 and score becomes 1.
    2. Play the 3rd token (400) face down, your power becomes 500 and score becomes 0.
    3. Play the 1st token (200) face up, your power becomes 300 and score becomes 1.
    4. Play the 2nd token (300) face up, your power becomes 0 and score becomes 2.
    ```

## 想法
帶入 `Greedy` 的想法，每次有 `score` 就犧牲掉 1 `score` 換最大的 `power`；沒有 `score` 的時候就犧牲掉最小的 `power` 換 1 `score`。


## 程式碼
```cpp
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left=0, right = tokens.size()-1, score=0, maximum=0;
        while(left <= right){
            if(power < tokens[left] && score>=1){
                power+=tokens[right];
                score-=1;
                right--;
            }
            else if(power >= tokens[left]){
                score+=1;
                power-=tokens[left];
                maximum = max(maximum, score);
                left++;
            }
            else{
                score=0;
                break;
            }
        }
        return maximum;
    }
};
```

![](https://imgur.com/Et6ANEM.png)

## 分類
`Two Pointers`、`Greedy`