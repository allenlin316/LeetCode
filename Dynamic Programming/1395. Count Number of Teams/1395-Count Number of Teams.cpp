#include <iostream>
#include <vector>
using namespace std;

int numTeams(vector<int>& rating);

int main()
{
    vector<int> rating;
    int num;
    while(cin >> num){
        rating.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << numTeams(rating);
}

int numTeams(vector<int>& rating) {
    // e.g.  [2,5,3,4,1]
    // large_dp[i] : rating[i] 的左邊數值大於 rating[i] 共有幾個
    // small_dp[i] : rating[i] 的左邊數值小於 rating[i] 共有幾個 
    int length = rating.size();
    int small_dp[length];
    int large_dp[length];
    for(int i=0; i<length; i++){small_dp[i] = large_dp[i] = 0;} // initialize
    int cnt=0;
    small_dp[0] = large_dp[0] = 0;
    for(int i=1; i<length; i++){
        for(int j=0; j<i; j++){
            if(rating[i] < rating[j]){
                cnt += large_dp[j]; // 代表可以組成一組遞減數列
                large_dp[i]++;
            }
            else{
                cnt += small_dp[j]; // 代表可以組成一組遞增數列
                small_dp[i]++;
            }
        }
    }
    return cnt;
}
