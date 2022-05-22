#include <iostream>
#include <valarray>     // std::valarray
using namespace std;

int total(int *dp);
int countVowelStrings(int n);

int main()
{
    int n;
    cin >> n;
    cout << countVowelStrings(n);
}

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
