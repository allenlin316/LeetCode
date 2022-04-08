#include <iostream>
#include <vector>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot);

int main()
{
    vector<int> nums;
    int num, pivot;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cin >> pivot;
    nums = pivotArray(nums, pivot);
    for(auto num : nums)
        cout << num << " ";
}

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int left = 0, right = nums.size()-1, i=0;
    vector<int> result(nums.size(), 0);
    while(left<right && i<nums.size()){
        if(nums[i]<pivot)    result[left++]=nums[i];
        if(nums[nums.size()-i-1]>pivot)   result[right--]=nums[nums.size()-i-1];
        i++;
    }
    for(int j=left; j<=right; j++)
        result[j] = pivot;

    return result;
}
