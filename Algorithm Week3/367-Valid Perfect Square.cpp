#include <iostream>

using namespace std;

bool isPerfectSquare(int num);

int main()
{
    int num;
    cin >> num;
    cout << isPerfectSquare(num);
}

bool isPerfectSquare(int num) {
    long int left = 1, right = num, mid;
    while(left <= right){
        mid = (left+right)/2;
        if(num > mid*mid)
            left = mid+1;
        else if(num < mid*mid)
            right = mid-1;
        else
            return true;
    }
    return false;
}
