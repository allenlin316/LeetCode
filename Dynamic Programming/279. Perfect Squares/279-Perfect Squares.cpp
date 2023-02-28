#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n);

int main()
{
    int n;
    while(cin >> n){
        cout << numSquares(n) << endl;
    }
    //cout << numSquares(n);
}

int numSquares(int n) {
    vector<int> dp(n+1, 100000); // initialize
    int minimum;
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=1; j*j<=i; j++){
            int remain = i-j*j;
            dp[i] = min(dp[i], dp[remain]+1);
        }
    }
    return dp[n];
}
