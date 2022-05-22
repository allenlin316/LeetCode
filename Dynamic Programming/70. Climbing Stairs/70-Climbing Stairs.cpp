#include <iostream>
using namespace std;

int climbStairs(int n);

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
}

int climbStairs(int n) {
    int steps[n+1];
    for(int i=0; i<=n; i++) steps[i]=0; // initialize
    steps[0] = steps[1] = 1; // zero and first steps both have only one way  
    for(int i=2; i<=n; i++){
        steps[i] = steps[i-1] + steps[i-2];
    }
    return steps[n];
}
