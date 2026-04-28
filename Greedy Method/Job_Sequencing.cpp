#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    
    int n = deadline.size();
    vector<pair<int,int>> jobs;

    // store (profit, deadline)
    for(int i = 0; i < n; i++){
        jobs.push_back({profit[i], deadline[i]});
    }

    // sort by profit descending
    sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

    // find max deadline
    int maxDeadline = 0;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    // slot array (0 = empty, 1 = filled)
    vector<int> slot(maxDeadline, 0);

    int cnt = 0;
    int totalProfit = 0;

    // iterate jobs
    for(int i = 0; i < n; i++){
        int start = jobs[i].second - 1;

        // try to place job in latest possible slot
        for(int j = start; j >= 0; j--){
            if(slot[j] == 0){
                slot[j] = 1;
                cnt++;
                totalProfit += jobs[i].first;
                break;
            }
        }
    }

    return {cnt, totalProfit};
}

int main() {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};

    vector<int> result = jobSequencing(deadline, profit);

    cout << "Jobs done: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;

    return 0;
}