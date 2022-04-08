#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int triangleNumber(vector<int>& nums);

int main()
{
    vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << triangleNumber(nums);
}

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int length = nums.size(), left, right, result=0;
    for(int i=length-1; i>=0; i--){
        left=0, right=i-1;
        while(left <= right){   // binary-search
            if(nums[left]+nums[right] > nums[i]){
                result += (right-left); // �]���⥪����w���k�@������k���w�e���@�w�ŦX���䤧�M�j��ĤT��
                right--;
            }
            else
                left++;
        }
    }
    return result;
}



