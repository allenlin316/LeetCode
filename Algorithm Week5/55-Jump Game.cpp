#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums);

int main()
{
    stringstream ss;
    int num;
    string inputArr;
    vector<int> nums;
    getline(cin, inputArr);
    ss << inputArr;
    while(ss >> num){
        nums.push_back(num);
    }
    cout << canJump(nums);
}

bool canJump(vector<int>& nums) {
    // 3,2,1,0,4
    int farthestEnd=0, cur;
    for(int i=0; i<nums.size(); i++){
        cur = nums[i];
        if(i > farthestEnd) return false;   // �N��̻��ਫ���Z���p��ثe�� index�A�]�N�O������ثe�� index
        farthestEnd = max(farthestEnd, cur+i); // (cur+i) : �e�����L��(i)�[�W�ۤv�̪����Z��(cur)
    }
    if(farthestEnd >= nums.size()-1)    return true;
    return false;
}

