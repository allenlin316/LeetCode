#include <iostream>
#include <algorithm>
using namespace std;

int minPartitions(string n);

int main()
{
    string str;
    cin >> str;
    cout << minPartitions(str);
}

int minPartitions(string n) {
    int result=0;
    char ch;
    for(int i=9; i>0; i--){
        ch = i+'0';
        result = n.find(ch);
        if(result != -1)
            break;
    }
    return n[result]-'0';
}
