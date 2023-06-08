#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 暴力求解，没什么意思
class Solution {
public:
    int ans;
    int tilingRectangle(int n, int m) {
        ans = max(n, m);
        vector<vector<int>> rect(n, vector<int>(m, 0));
        dfs(0, 0, rect, 0);
        return ans;
    }

    void dfs(int x, int y, vector<vector<int>> & rect, int cnt) {
        int n = rect.size(), m = rect[0].size();
        if (cnt >= ans) {
            return;
        }
        if (x >= n) {
            ans = cnt;
            return;
        }

        if (y >= m) {
            dfs(x + 1, 0, rect, cnt);
            return;
        }

        if (rect[x][y]) {
            dfs(x, y + 1, rect, cnt);
            return;
        }

        for (int k = min(n - x, m - y); k >= 1 && isAvailable(rect, x, y, k); --k) {
            fillUp(rect, x, y, k, 1);
            dfs(x, y + k, rect, cnt + 1);
            fillUp(rect, x, y, k, 0);
        }
    }

    bool isAvailable(vector<vector<int>> & rect, int x, int y, int k) {
        for (int i = 0; i < k; ++i) {
            if (accumulate(rect[x + i].begin() + y, rect[x + i].begin() + y + k, 0)) {
                return false;
            }
        }
        return true;
    }

    void fillUp(vector<vector<int>> &rect, int x, int y, int k, int val) {
        for (int i = 0; i < k; ++i) {
            fill(rect[x + i].begin() + y, rect[x + i].begin() + y + k, val);
        }
    }
};

int main() {
    Solution s;
    int n, m;
    cin >> n >> m;
    cout << s.tilingRectangle(n, m) << endl;
}