#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums);
void selectionSort(vector<int> &nums);
void quickSort(vector<int> &nums, int left, int right);

int main()
{
    vector<int> nums = {7,5,1,4,3};
    int num, left = 0, right = nums.size()-1;
    insertionSort(nums);
    //selectionSort(nums);
    //quickSort(nums, left, right);
    for(auto num : nums)
        cout << num << " ";
}

void insertionSort(vector<int> &nums){
    for(int i=1; i<nums.size(); i++){
        int x = nums[i];
        int j = i-1;
        while(nums[j]>x && j>=0){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = x;
    }
}

void selectionSort(vector<int> &nums){
    for(int i=0; i<nums.size()-1; i++){
        int f = i;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[f] > nums[j])
                f = j;
        }
        swap(nums[i], nums[f]);
    }
}

void quickSort(vector<int> &nums, int left, int right){
    if(left >= right)   return;
    int pivot = nums[left];
    int i = left+1;
    int j = right;
    while(i < j){
        while(nums[i]<= pivot)   i++;
        while(nums[j] >= pivot) j--;
        if(i < j)   swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[j]);
    quickSort(nums, left, j-1);
    quickSort(nums, j+1, right);
}
