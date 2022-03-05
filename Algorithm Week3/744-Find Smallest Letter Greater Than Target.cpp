#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target);

int main()
{
    string inputArr;
    char ch, target;
    vector<char> letters;
    stringstream ss;
    getline(cin, inputArr);
    cin >> target;
    ss << inputArr;
    while(ss >> ch){
        letters.push_back(ch);
    }
    cout << nextGreatestLetter(letters, target);
}

char nextGreatestLetter(vector<char>& letters, char target) {
    // letters=c, f, j , target= a
    // result set to '0' cuz the wrap around case like [a,b] target=z, Output=a
    int left = 0, right = letters.size()-1, mid, result=0;
    while(left <= right){
        mid = (left+right)/2;
        // we only want char which is larger than target, not less or equal to target
        if(target >= letters[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
            result = mid;
        }
    }
    return letters[result];
}
