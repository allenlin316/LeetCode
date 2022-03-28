#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int jump(vector<int>& nums);

int main()
{
    stringstream ss;
    vector<int> nums;
    string inputArr;
    int num;
    getline(cin, inputArr);
    ss << inputArr;
    while(ss >> num){
        nums.push_back(num);
    }
    cout << jump(nums);
}

int jump(vector<int>& nums) {
    // Input : 2, 3, 0, 1, 4
    // output : 2
    int farestEnd=0, cur=0, jump_cnt=0;
    for(int i=0; i<nums.size()-1; i++){
        farestEnd = max(farestEnd, nums[i]+i);
        if(cur >= nums.size())  break;
        if(cur == i){ // 當到達 cur 位置的時候，可以直接跳到 farestEnd，因為到 cur 前已經有人可以走到最遠的位置
            cur = farestEnd;
            jump_cnt++;
        }
    }
    return jump_cnt;
}
