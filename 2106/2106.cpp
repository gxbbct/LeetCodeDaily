#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* 向左走 x 步，再向右走 k - x 步 */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
            int end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, sum[end] - sum[start]);
            /* 向右走 x 步，再向左走 k - x 步 */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
            end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, sum[end] - sum[start]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> fruits;
    int startPos, k;
    string mstr, t1, t2;
    stringstream ss;
    int pf, nf;
    getline(cin, mstr);
    int cnt = 0;
    vector<int> tvec(2);
    for (int i = 0; i < mstr.length(); ++i) {
        if (mstr[i] != '\n') {
            if (mstr[i] == ' ') {
                continue;
            }
            if (mstr[i] != ',') {
                tvec[cnt++] = (stoi(string(1,mstr[i])));
                if (cnt == 2) {
                    fruits.push_back(tvec);
                    cnt = 0;
                }
            }
        }
    }
    cin >> startPos >> k;
    cout << s.maxTotalFruits(fruits, startPos, k) << endl;
}