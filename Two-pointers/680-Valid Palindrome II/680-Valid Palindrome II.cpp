#include <iostream>
using namespace std;

bool validPalindrome(string s);
bool isPalindrome(string s, int left, int right);

int main()
{
    string str;
    cin >> str;
    cout << validPalindrome(str);
}

bool validPalindrome(string s) {
    // abbca�Babca�Babbcca�Babc
    // "ebcbbececabbacecbbcbe" = ebcbbcecabbacecebbcbe
    int left=0, right=s.size()-1;
    while(left<right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else{
            return (isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1));
        }
    }
    return true;
}

bool isPalindrome(string s, int left, int right){
    while(left < right){
         if(s[left] != s[right])    return false;
        left++;
        right--;
    }
    return true;
}
