#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int minimumSum(int num);

int main()
{
    int num;
    cin >> num;
    cout << minimumSum(num);
}

int minimumSum(int num) {
    stringstream ss;
    vector<int> arr(4,0);
    int new1, new2, i=0;
    char digit;
    ss << num;
    while(ss >> digit){
        arr[i++] = digit-'0';
    }
    sort(arr.begin(), arr.end());
    return (arr[0]*10+arr[2] + arr[1]*10 + arr[3]);
}
