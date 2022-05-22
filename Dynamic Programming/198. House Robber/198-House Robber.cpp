#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums);

int main()
{
    vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << rob(nums);
}

int rob(vector<int>& nums) {
    // dp[i] : 至第 i 戶最大金額
    if(nums.size() == 1) // only one house
        return nums[0];
    int dp[nums.size()];
    for(int i=0; i<nums.size(); i++)   dp[i] = 0; // initialize
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<nums.size(); i++){
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[nums.size()-1];
}
