#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, bool first);
vector<int> searchRange(vector<int>& nums, int target);

int main()
{
    vector<int> nums;
    vector<int> result;
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
    result = searchRange(nums, target);
    cout << "Output: ";
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";
}

vector<int> searchRange(vector<int>& nums, int target){
    bool first = true;
    int firstFound = binarySearch(nums, target, first);
    int secondFound = binarySearch(nums, target, !first);
    vector<int> result{firstFound, secondFound};
    return result;
}

int binarySearch(vector<int>& nums, int target, bool first){
    int left = 0, mid, ans=-1;
    int right = nums.size()-1;
    while(left <= right){
        mid = (left+right)/2;
        if(nums[mid] < target)
            left = mid+1;
        else if(nums[mid] > target)
            right = mid-1;
        else{
            ans = mid;
            if(first) right = mid-1;
            else   left = mid+1;
        }
    }
    return ans;
}
