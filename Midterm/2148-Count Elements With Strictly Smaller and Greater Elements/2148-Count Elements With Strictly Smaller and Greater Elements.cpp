#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countElements(vector<int>& nums);

int main()
{
    int num;
    vector<int> nums;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << countElements(nums);
}

int countElements(vector<int>& nums){
    int left=0, right=nums.size()-1, cnt=0;
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++){
        if(nums[i] != nums[left])
            break;
        left++;
    }
    // 2 7 11 15
    for(int i=nums.size()-2; i>0; i--){
        if(nums[i] != nums[right])
            break;
        right--;
    }
    for(int i=left+1; i<right; i++)
        cnt++;
    return cnt;
}
