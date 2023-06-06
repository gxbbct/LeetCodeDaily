#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        // 这里不能用unordered_map, 除非把vector<int>换成string
        map<vector<int>, int> cnt;
        for (auto & row : grid) {
            ++cnt[row];
        }
        
        int res = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> arr;
            for (int i = 0; i < n; ++i) {
                arr.emplace_back(grid[i][j]);
            }
            if (cnt.count(arr)) {
                res += cnt[arr];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << s.equalPairs(grid) << endl;
}