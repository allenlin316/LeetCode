#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int maxArea(vector<int>& height);

int main()
{
    stringstream ss;
    vector<int> height;
    string inputArr;
    int num;
    getline(cin, inputArr);
    ss << inputArr;
    while(ss >> num){
        height.push_back(num);
    }
    cout << maxArea(height) << endl;
}

int maxArea(vector<int>& height){
    int left=0, right=height.size()-1, volume=0, maximum=0;
    while(left < right){
        if(height[left] < height[right]){
            volume = (right-left) * height[left];
            left++;
        }
        else if(height[left] > height[right]){
            volume = (right - left) * height[right];
            right--;
        }
        else{
            volume = (right - left) * height[left];
            left++;
        }
        maximum = (volume > maximum) ? volume : maximum;
    }
    return maximum;
}
