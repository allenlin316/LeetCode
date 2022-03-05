#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool search(vector<int>& nums, int target);

int main()
{
    stringstream ss;
    string inputArr;
    int num, target;
    vector<int> nums;
    getline(cin, inputArr);
    cin >> target;
    ss << inputArr;
    while(ss >> num){
        nums.push_back(num);
    }
    cout << search(nums, target) << endl;
}

bool search(vector<int>& nums, int target){
    // init : 2 5 6 0 0 1 2
    int cnt=0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i] > nums[i+1]){
            cnt = i+1;
            break;
        }
    }
    // imagine : 2 5 6 0 0 1 2 2 5 6, which 2 5 6 were assumed to be appended to the back
    int left = cnt, right = cnt+nums.size()-1, mid, imagine_arr_mid;
    while(left <= right){
        imagine_arr_mid = (left+right)/2; // we actually do binary_search on 0,0,1,2,2,5,6
        mid = imagine_arr_mid % nums.size();
        if(target > nums[mid])
            left = imagine_arr_mid+1;
        else if(target < nums[mid])
            right = imagine_arr_mid-1;
        else
            return true;
    }
    return false;
}

