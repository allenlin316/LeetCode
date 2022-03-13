#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

string removeNonAlphanumeric(string str);
bool isPalindrome(string s);

int main()
{
    string inputString, str, s="";
    stringstream ss;
    getline(cin, inputString);
    ss << inputString;
    while(ss >> str){
        s += str;
    }
    cout << isPalindrome(s);
}

string removeNonAlphanumeric(string str){
    string result="";
    for(int i=0; i<str.size(); i++){
        if(str[i]>= '0' && str[i]<='9' || str[i]>='a' && str[i]<='z')
            result += str[i];
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            char ch = tolower(str[i]);
            result += ch;
        }
    }
    return result;
}

bool isPalindrome(string s) {
    s = removeNonAlphanumeric(s);
    int left = 0, right = s.size()-1, s_half_length = s.size()/2;
    while(s_half_length--){
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
