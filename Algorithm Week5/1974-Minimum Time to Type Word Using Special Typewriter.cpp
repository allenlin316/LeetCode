#include <iostream>
#include <cmath>
using namespace std;

int minTimeToType(string word);
bool moveClockwise(int cur, char ch);

int main()
{
    string word;
    cin >> word;
    cout << minTimeToType(word);
}

bool moveClockwise(int cur, char ch){
    if(abs(ch - cur) > 13)  // �Z���L�F�b��N���f�ɰw�|�����
        return false;
    else
        return true;
}

int minTimeToType(string word) {
    // word = bza, word = zjpc
    int cur = 'a', result=0, moveTimes; // initial
    for(int i=0; i<word.size(); i++){
        if(moveClockwise(cur, word[i])){
            moveTimes = abs(word[i] - cur);
        }
        else{
            moveTimes = 26-abs(word[i] - cur);
        }
        result += moveTimes +1;
        cur = word[i]; // change current pointer
    }
    return result;
}
