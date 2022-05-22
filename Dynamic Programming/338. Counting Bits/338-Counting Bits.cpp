#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n);

int main()
{
    int n;
    vector<int> res;
    cin >> n;
    res = countBits(n);
    for(auto num : res)
        cout << num << " ";
}

vector<int> countBits(int n) {
    if(n==0) // 因為後面會宣告 dp[1] 所以預防 overflow 這邊直接回傳
        return {0};
    vector<int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<n+1; i++){
        if(i%2 == 0)
            dp[i] = dp[i/2];
        else
            dp[i] = dp[i-1] + 1;
    }
    return dp;
}
