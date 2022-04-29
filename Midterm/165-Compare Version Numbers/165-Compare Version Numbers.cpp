#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int compareVersion(string version1, string version2);

int main()
{
    string version1, version2;
    cin >> version1 >> version2;
    cout << compareVersion(version1, version2);
}

int compareVersion(string version1, string version2) {
    vector<int> v1;
    vector<int> v2;
    string delim = ".";
    int num, pos, i=0, j=0;
    while((pos=version1.find(delim)) != -1){    // 分割字串
        v1.push_back(stoi(version1.substr(0, pos)));
        version1.erase(0, pos+1);
    }
    while((pos=version2.find(delim)) != -1){    // 分割字串
        v2.push_back(stoi(version2.substr(0, pos)));
        version2.erase(0, pos+1);
    }
    v1.push_back(stoi(version1)); // 把剩下的字串放進去
    v2.push_back(stoi(version2));
    while(v1.size() < v2.size())    // 補足長度不一樣的問題
        v1.push_back(0);
    while(v2.size() < v1.size())
        v2.push_back(0);
    while(i<v1.size() && j<v2.size()){
        if(v1[i] > v2[j])   return 1;
        else if(v1[i] < v2[j])  return -1;
        i++;
        j++;
    }
    return 0;
}
