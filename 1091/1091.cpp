#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS, 效率比较高
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 0x3f3f3f3f));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }
            for (int dx = -1; dx <= 1; ++dx){
                for (int dy = -1; dy <= 1; ++dy) {
                    if (x + dx < 0 || x + dx >=n || y + dy < 0 || y + dy >=n) {
                        continue;
                    }
                    // dist[x + dx][y + dy] <= dist[x][y] + 1 这一句决定了搜出来的就是最短路径，因为会更新每个节点的代价
                    if (grid[x + dx][y + dy] == 1 || dist[x + dx][y + dy] <= dist[x][y] + 1) {
                        continue;
                    }
                    dist[x + dx][y + dy] = dist[x][y] + 1;
                    q.push({x + dx, y + dy});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> t(n);
        for (int j = 0; j < n; ++j) {
            cin >> t[j];
        }
        grid.push_back(t);
    }
    cout << s.shortestPathBinaryMatrix(grid) << endl;
}