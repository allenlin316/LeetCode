#include <iostream>
#include <vector>
using namespace std;

void backTracking(vector<string> &res, string cur, int open, int close, int n);
vector<string> generateParenthesis(int n);

int main()
{
    int n;
    vector<string> res;
    cin >> n;
    res = generateParenthesis(n);
    for(auto str : res)
        cout << str << " ";
}

void backTracking(vector<string> &res, string cur, int open, int close, int n){
    if(cur.size() >= n*2){
        res.push_back(cur);
        return;
    }

    if(open < n)
        backTracking(res, cur+"(", open+1, close, n);

    if(close < open)
        backTracking(res, cur+")", open, close+1, n);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backTracking(res, "", 0, 0, n);
    return res;
}
