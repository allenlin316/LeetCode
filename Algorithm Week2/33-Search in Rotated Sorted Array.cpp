#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target);
int search(vector<int>& nums, int target);

int main()
{
    vector<int> nums;
    string inputArr;
    int target, num;
    stringstream ss;
    cout << "Input Array: ";
    getline(cin, inputArr);
    cout << "Input target: ";
    cin >> target;
    ss << inputArr;
    while(ss >> num){
        nums.push_back(num);
    }
    cout << "Output: " << search(nums, target);
}

int search(vector<int>& nums, int target){
    int left = 0, first_of_nums = nums[0], target_before_rotate, pivot;
    int right = nums.size()-1;
    sort(nums.begin(), nums.end());
    // binary-search for pivot
    pivot = binarySearch(nums, first_of_nums);
    // binary-search for target
    target_before_rotate = binarySearch(nums, target);
    if(target_before_rotate == -1)
        return -1;
    // pivot 後的數字處理
    if(target_before_rotate-pivot >= 0)
        return (target_before_rotate-pivot);
    // pivot 前的數字處理
    if(target_before_rotate-pivot < 0)
        return (nums.size()-pivot + target_before_rotate);
}

int binarySearch(vector<int> &nums, int target){
    int left = 0, mid, right = nums.size()-1;
    while(left <= right){
        mid = (left+right)/2;
        if(nums[mid] < target)
            left = mid+1;
        else if(nums[mid] > target)
            right = mid-1;
        else{
            return mid;
        }
    }
    return -1;
}


