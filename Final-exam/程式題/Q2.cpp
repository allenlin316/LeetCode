#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n, total=0;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        total=0;
        for(int j=0; j<n; j++){
            total += (dp[j]*dp[n-1-i]);
            dp[i] = total;
        }
    }
    cout << dp[n];
}
