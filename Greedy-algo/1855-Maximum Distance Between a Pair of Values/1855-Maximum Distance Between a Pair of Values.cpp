#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2);

int main()
{
    int num;
    vector<int> nums1;
    vector<int> nums2;
    while(cin >> num){
        nums1.push_back(num);
        if(cin.get() == '\n')   break;
    }
    while(cin >> num){
        nums2.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << maxDistance(nums1, nums2);
}

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int maximum = 0, left=0, right=nums2.size()-1, mid;
    for(int i=0; i<nums1.size(); i++){
        if(maximum >= nums2.size()-1-i)   break;
        left = i;
        right = nums2.size()-1;
        while(left <= right){
            mid = (left+right) / 2;
            if(nums1[i] > nums2[mid])
                right = mid-1;
            else{
                maximum = max(maximum, mid - i);
                left = mid+1;
            }
        }
    }
    return maximum;
}
