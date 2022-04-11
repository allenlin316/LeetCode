#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numRescueBoats(vector<int>& people, int limit);

int main()
{
    int num, limit;
    vector<int> people;
    while(cin >> num){
        people.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cin >> limit;
    cout << numRescueBoats(people, limit);
}

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int left=0, right=people.size()-1, boat=0;
    while(left < right){
        if(people[left] + people[right] <= limit){
            right--;
            left++;
            boat++;
        }
        else{
            right--;
            boat++;
        }
    }
    if(left == right)   boat++;
    return boat;
}
