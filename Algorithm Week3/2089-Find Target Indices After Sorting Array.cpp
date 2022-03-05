#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target);

int main()
{
    stringstream ss;
    string inputArr;
    int num, target;
    vector<int> nums;
    getline(cin, inputArr);
    cin >> target;
    ss << inputArr;
    while(ss >> num){
        nums.push_back(num);
    }
    nums = targetIndices(nums, target);
    for(int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
}

vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> result;
    int left = 0, right=nums.size()-1, mid, index=-1;
    while(left <= right){
        mid = (right+left)/2;
        if(nums[mid] < target)
            left = mid+1;
        else if(nums[mid] > target)
            right = mid-1;
        else{
            right = mid-1;
            index = mid;
        }
    }
    if(index == -1)
        return vector<int>();
    while(index <= nums.size()-1 && nums[index] == target){
        result.push_back(index);
        index+=1;
    }
    return result;
}
