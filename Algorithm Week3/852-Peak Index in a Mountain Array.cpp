#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr);

int main()
{
    string inputArr;
    int num;
    vector<int> arr;
    stringstream ss;
    getline(cin, inputArr);
    ss << inputArr;
    while(ss >> num){
        arr.push_back(num);
    }
    cout << peakIndexInMountainArray(arr);
}

int peakIndexInMountainArray(vector<int>& arr) {
        // arr : 0 1 2 0
        int left = 1, right = arr.size()-2, mid;
        while(left <= right){
            mid = (left+right)/2;
            if(arr[mid] < arr[mid-1])
                right = mid-1;
            else if(arr[mid] < arr[mid+1])
                left = mid+1;
            else
                return mid;
        }
        return -1;
}
