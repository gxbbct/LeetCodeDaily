#include <iostream>
#include <vector>
using namespace std;

//这样写会超时
/*class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<int> f(n);
        f[0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            f[i] = max(f[i-1], jobDifficulty[i]);
        }
        if (n < d || d < 1) {
            return -1;
        }
        return dp(jobDifficulty, f, d, n);
    }
    int dp(vector<int>& jobDifficulty, vector<int>& f, const int& d, const int& j) {
        int ans = INT_MAX;
        if (d == 1) {
            return f[j-1];
        } else {
            for (int k = d - 1; k < j; ++k) {
                int tmax = 0;
                for (int t = k; t < j; ++t) {
                    tmax = max(tmax, jobDifficulty[t]);
                }
                ans = min(ans, dp(jobDifficulty, f, d - 1, k) + tmax);
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d + 1, vector<int>(n, INT_MAX));
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ma = max(ma, jobDifficulty[i]);
            dp[0][i] = ma;
        }
        for (int i = 1; i < d; ++i) {
            for (int j = i; j < n; ++j) {
                ma = 0;
                for (int k = j; k >= i; --k) {
                    ma = max(ma, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], ma + dp[i - 1][k - 1]);
                }
            }
        }
        return dp[d - 1][n - 1];
    }        
};

int main() {
    Solution s;
    vector<int> jobDifficulty;
    int t;
    while (cin >> t) {
        jobDifficulty.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    int d;
    cin >> d;
    cout << s.minDifficulty(jobDifficulty,d) << endl;
}