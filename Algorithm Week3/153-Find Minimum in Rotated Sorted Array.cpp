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
        if(nums[left] < nums[mid]) // ��ܼƦC������S���Q rotate
            left = mid;
        else if(nums[right] > nums[mid]) // ��ܼƦC���k��S���Q rotate
            right = mid;
        else{
            if(nums[mid] > nums[mid+1]) // �Ҽ{��� left �P mid ���|�A�S nums[right]<nums[mid]
                return nums[mid+1];
            else if(nums[mid] < nums[mid-1])  // �Ҽ{��� right �P mid ���|�A�S nums[mid]<nums[left]
                return nums[mid];
            else
                return -1;  // �]���D�ػ��Ʀr���O�����ơA�ҥH�o���P�_�����|�i��
        }
    }
    return nums[0]; // ��ܼƦr�@�}�l���S����A�άO�Ʀr�৹�٬O�����@�˶���
}
