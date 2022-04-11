#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> diStringMatch(string s);

int main()
{
    string str;
    vector<int> result;
    cin >> str;
    result = diStringMatch(str);
    for(auto num : result)
        cout << num << " ";
}

vector<int> diStringMatch(string s) {
    vector<int> nums(s.size()+1, 0);
    int left = 0, right = nums.size()-1, i=0;
    while(left <= right){
        if(s[i] == 'I') nums[i] = left++;
        else    nums[i] = right--;
        i++;
    }
    return nums;
}
