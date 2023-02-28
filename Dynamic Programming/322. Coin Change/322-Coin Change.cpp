#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount);

int main()
{
    vector<int> coins;
    int num, amount;
    while(cin >> num){
        coins.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cin >> amount;
    cout << coinChange(coins, amount);
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for(int i=1; i<=amount; i++){
        for(int j=0; j<coins.size(); j++){
            int remain = i - coins[j];
            if(remain >= 0)
                dp[i] = min(dp[remain]+1, dp[i]);
        }
    }
    return (dp[amount] >= amount+1) ? -1 : dp[amount];
}
