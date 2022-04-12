#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power);

int main()
{
    vector<int> tokens;
    int power, num;
    while(cin >> num){
        tokens.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cin >> power;
    cout << bagOfTokensScore(tokens, power);
}

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int left=0, right = tokens.size()-1, score=0, maximum=0;
    while(left <= right){
        if(power < tokens[left] && score>=1){
            power+=tokens[right];
            score-=1;
            right--;
        }
        else if(power >= tokens[left]){
            score+=1;
            power-=tokens[left];
            maximum = max(maximum, score);
            left++;
        }
        else{
            score=0;
            break;
        }
    }
    return maximum;
}
