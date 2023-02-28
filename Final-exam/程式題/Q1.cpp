#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 0;
    for(int i=2; i<n+1; i++){
        if(i%2 == 0)
            dp[i] = dp[i/2]+1;
        else
            dp[i] = dp[i-1]-1;
    }
    cout << dp[n];
}
