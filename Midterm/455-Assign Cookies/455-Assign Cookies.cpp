#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);

int main()
{
    vector<int> g;
    vector<int> s;
    int num;
    while(cin >> num){
        g.push_back(num);
        if(cin.get() == '\n')   break;
    }
    while(cin >> num){
        s.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << findContentChildren(g, s);
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    int cnt=0, i=0, j=0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    // 1 2 3
    // 1 1
    while(i < g.size() && j < s.size()){
        if(g[i] <= s[j]){
            i++;
            j++;
           cnt++;
        }
        else
            j++;
    }
    return cnt;
}
