#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> // pair
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker);

int main()
{
    vector<int> difficulty;
    vector<int> profit;
    vector<int> worker;
    int num;
    cout << "difficult: ";
    while(cin >> num){
        difficulty.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << "profit: ";
    while(cin >> num){
        profit.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << "worker: ";
    while(cin >> num){
        worker.push_back(num);
        if(cin.get() == '\n')   break;
    }
    cout << maxProfitAssignment(difficulty, profit, worker);
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int total=0, maximum=0, j=0;
    vector<pair<int,int>> job;
    for(int i=0; i<profit.size(); i++)
        job.push_back(make_pair(difficulty[i], profit[i]));
    sort(job.begin(), job.end());
    sort(worker.begin(), worker.end());
    for(int i=0; i<worker.size(); i++){
        while(worker[i]>=job[j].first && j<job.size())
            maximum = max(maximum, job[j++].second);
        total += maximum;
    }
    return total;
}
