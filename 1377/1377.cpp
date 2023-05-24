#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS，因为有步数的限制，比较适合
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < edges.size(); ++i) {
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n + 1, 0);
        queue<pair<int, double>> Q;
        Q.push({1, 1.0});
        visited[1] = 1;
        for (; Q.size() && t >= 0; --t) {
            for (int k = Q.size(); k; --k) {
                auto [u, p] = Q.front();
                Q.pop();
                int cnt = G[u].size() - (u != 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                for (int v : G[u]) {
                    if (visited[v] == 0) {
                        visited[v] = 1;
                        Q.push({v, p/cnt});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> edges[i][j];
        }
    }
    int t, target; 
    cin >> t >> target;
    cout << s.frogPosition(n, edges, t, target) << endl;
}