#include<iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i=0; i<nums.size(); i++){
        int firstNum = nums[i];
        for(int j=i+1; j<nums.size(); j++){
            if(firstNum + nums[j] == target){
                result = {i, j};
            }
        }
    }
    return result;
}

int main()
{
    vector<int> num;
    int target, input;
    while(cin>>input){
        num.push_back(input);
        if(cin.get()=='\n')   break;
    }
    cin >> target;
    num = twoSum(num, target);
    for(auto index : num)
        cout << index << " ";
}
