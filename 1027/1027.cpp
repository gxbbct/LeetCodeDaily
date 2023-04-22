#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int> &a) {
        int ans = 0, n = a.size(), f[n][1001];
        memset(f, 0, sizeof(f));
        for (int i = 1; i < n; ++i)
            for (int j = i - 1; j >= 0; --j) {
                int d = a[i] - a[j] + 500; // +500 防止出现负数
                if (f[i][d] == 0) {
                    f[i][d] = f[j][d] + 1; // 默认的 1 在下面返回时加上
                    ans = max(ans, f[i][d]);
                }
            }
        return ans + 1;
    }
};

int main(){
    Solution s;
    vector<int> data{3,6,9,12};
    cout << s.longestArithSeqLength(data) << endl;
}