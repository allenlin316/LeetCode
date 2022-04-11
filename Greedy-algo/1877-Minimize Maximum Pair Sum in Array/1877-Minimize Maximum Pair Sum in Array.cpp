#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minPairSum(vector<int>& nums);

int main()
{
    vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << minPairSum(nums);
}

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left=0, right = nums.size()-1, maximum=0;
    while(left < right){
        maximum = max(maximum, nums[left++] + nums[right--]);
    }
    return maximum;
}
