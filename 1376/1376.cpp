#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        // 找到所有人的直接下属
        for (int i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                g[manager[i]].push_back(i);
            }
        }
        function<int(int)> dfs = [&](int i) -> int {
            int ans = 0;
            for (int j : g[i]) {
                ans = max(ans, dfs(j) + informTime[i]);
            }
            return ans;
        };
        return dfs(headID);
    }
};

int main() {
    Solution s;
    int n, headID;
    cin >> n >> headID;
    vector<int> manager(n);
    for (int i = 0; i < n; ++i) {
        cin >> manager[i];
    }
    vector<int> informTime(n);
    for (int i = 0; i < n; ++i) {
        cin >> informTime[i];
    }
    cout << s.numOfMinutes(n, headID, manager, informTime) << endl;   
}