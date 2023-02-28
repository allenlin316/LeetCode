#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums);

int main()
{
    int num;
    vector<int> nums;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << maxSubArray(nums);
}

int maxSubArray(vector<int>& nums) {
    // dynamic-programming, Kadane Algo.
    int maximum = nums[0];
    for(int i=1; i<nums.size(); i++){
        nums[i] = max(nums[i], nums[i-1]+nums[i]);
        maximum = max(maximum, nums[i]);
    }
    return maximum;
}
