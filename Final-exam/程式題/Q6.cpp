#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nums_size, num, maximum;
    vector<int> nums;
    cin >> nums_size;
    for(int i=0; i<nums_size; i++){
        cin >> num;
        nums.push_back(num);
    }
    vector<int> dp(nums_size, (-1)*nums_size);
    dp[0] = nums[0];
    maximum = dp[0];
    for(int i=1; i<nums_size; i++){
        dp[i] = max(nums[i], dp[i-1]+nums[i]);
        maximum = max(maximum, dp[i]);
    }
    cout << maximum;
}
