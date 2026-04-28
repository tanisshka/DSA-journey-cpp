#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // DSU find with path compression
    int find(int x, vector<int> &parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();
        vector<pair<int,int>> jobs;

        // store (profit, deadline)
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // sort by profit descending
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

        // find max deadline
        int maxDeadline = 0;
        for(int d : deadline) {
            maxDeadline = max(maxDeadline, d);
        }

        // initialize DSU
        vector<int> parent(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int cnt = 0;
        int totalProfit = 0;

        // process jobs
        for(auto job : jobs) {

            int d = job.second;

            // find latest available slot
            int availableSlot = find(d, parent);

            if (availableSlot > 0) {
                // assign job
                cnt++;
                totalProfit += job.first;

                // mark slot as filled
                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }

        return {cnt, totalProfit};
    }
};

int main() {
    vector<int> deadline = {2,6,6,5,4,2,4,2};
    vector<int> profit   = {80,70,65,60,25,22,20,10};

    Solution obj;
    vector<int> result = obj.jobSequencing(deadline, profit);

    cout << "Jobs done: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;

    return 0;
}