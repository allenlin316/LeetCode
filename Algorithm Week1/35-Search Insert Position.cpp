#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target);

int main()
{
    vector<int> arr(6, 0);
    arr[0] = -1; arr[1] = 0;
    arr[2] = 3; arr[3] = 5;
    arr[4] = 9; arr[5] = 12;
    int target = 13;
    cout <<search(arr, target);
}

int search(vector<int>& nums, int target){
    // -1, 0, 3, 5, 9, 12
    int right = nums.size()-1;
    int left = 0;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(target < nums[mid])
            right = mid-1;
        else if(target > nums[mid])
            left = mid+1;
        else
            return mid;
    }
    return left;
}

