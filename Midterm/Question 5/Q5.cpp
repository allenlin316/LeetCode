#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, target;
    vector<int> nums;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cin >> target;
    int left = 0, right=nums.size()-1, mid, left_most_index=-1, right_most_index=-1;
    while(left <= right){
        mid = (left+right) / 2;
        if(nums[mid] > target)
            right = mid-1;
        else if(nums[mid] < target)
            left = mid+1;
        else{
            left_most_index = mid;
            right = mid-1;
        }
    }
    left =0, right = nums.size()-1;
    while(left <= right){
        mid = (left+right) / 2;
        if(nums[mid] > target)
            right = mid-1;
        else if(nums[mid] < target)
            left = mid+1;
        else{
            right_most_index = mid;
            left = mid+1;
        }
    }
    if(left_most_index == right_most_index && left_most_index==-1)
        cout << -1;
    else if( (left_most_index + right_most_index)%2!=0)
        cout << -2;
    else
        cout << (left_most_index+right_most_index)/2;
}

