#include <iostream>
#include <algorithm>
//#include <vector>
using namespace std;

int getMinSwaps(string num, int k);

int main()
{
    string str;
    int k;
    cin >> str >> k;
    cout << getMinSwaps(str, k);
}

int getMinSwaps(string num, int k) {
    string beforePerm = num;
    int cnt=0;
    while(k--)
        next_permutation(num.begin(), num.end());
    for(int i=0; i<num.size(); i++){
        if(num[i] != beforePerm[i]){
            int j = i+1;
            while(num[j] != beforePerm[i]){
                j++;
            }
            while(j > i){
                swap(num[j], num[j-1]);
                j--;
                cnt++;
            }
        }
    }
    return cnt;
}
