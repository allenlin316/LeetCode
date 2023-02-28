#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        for(int j=1; j*j<=i; j++){
            int remain = i-j*j;
            if(remain >= 0)
                dp[i] = min(dp[i], dp[remain]+1);
        }
    }
    cout << dp[n];
}
