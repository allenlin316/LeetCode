#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(vector<int> aDiff, vector<int> bDiff);
int twoCitySchedCost(vector<vector<int>>& costs);

int main()
{
    int aCost, bCost;
    vector<vector<int>> costs;
    while(cin >> aCost >> bCost){
        costs.push_back({aCost, bCost});
        if(cin.get() == '\n')   break;
    }
    cout << twoCitySchedCost(costs);
}

int twoCitySchedCost(vector<vector<int>>& costs) {
    for(int i=0; i<costs.size(); i++)
        costs[i].push_back({costs[i][0] - costs[i][1]}); // 去兩個地方的價錢差
    sort(costs.begin(), costs.end(), mycompare);
    int length = costs.size(), min_cost=0;
    for(int i=0; i<length/2; i++)
        min_cost += costs[i][0];
    for(int i=length/2; i<length; i++)
        min_cost += costs[i][1];
    return min_cost;
}

bool mycompare(vector<int> aDiff, vector<int> bDiff){
    if(aDiff[2] < bDiff[2]) return true;
    return false;
}
