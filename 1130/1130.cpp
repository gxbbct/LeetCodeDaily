#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f)), mval(n, vector<int>(n));
        // 区间右侧从左到右开始过
        for (int j = 0; j < n; ++j) {
            dp[j][j] = 0;
            mval[j][j] = arr[j];
            // 区间左侧从右侧减一开始过，且保证大于等于零
            for (int i = j - 1; i >= 0; --i) {
                mval[i][j] = max(arr[i], mval[i + 1][j]);
                // 中间隔开从左到右，但不会触碰到区间右端点
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> arr;
    int t;
    while (cin >> t) {
        arr.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << s.mctFromLeafValues(arr) << endl;
}