#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int findMin(vector<int>& nums);

int main()
{
    stringstream ss;
    string inputArr;
    int num;
    vector<int> nums;
    getline(cin, inputArr);
    ss << inputArr;
    while(ss >> num){
        nums.push_back(num);
    }
    cout << findMin(nums) << endl;
}

int findMin(vector<int>& nums){
    // 3,4,5,1,2    1,2,3,4,5
    int left = 0, right = nums.size()-1, mid;
    while(left < right){
        mid = (left + right)/2;
        if(nums[left] < nums[mid]) // 表示數列的左邊沒有被 rotate
            left = mid;
        else if(nums[right] > nums[mid]) // 表示數列的右邊沒有被 rotate
            right = mid;
        else{
            if(nums[mid] > nums[mid+1]) // 考慮到當 left 與 mid 重疊，又 nums[right]<nums[mid]
                return nums[mid+1];
            else if(nums[mid] < nums[mid-1])  // 考慮到當 right 與 mid 重疊，又 nums[mid]<nums[left]
                return nums[mid];
            else
                return -1;  // 因為題目說數字都是不重複，所以這條判斷式不會進來
        }
    }
    return nums[0]; // 表示數字一開始都沒有轉，或是數字轉完還是維持一樣順序
}
