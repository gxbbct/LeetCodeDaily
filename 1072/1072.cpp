#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> cnt;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            string s1, s2;
            for (int j = 0; j < n; ++j) {
                s1 += '0' + matrix[i][j];
                s2 += '1' - matrix[i][j];
            }
            res = max(res, ++cnt[s1]);
            res = max(res, ++cnt[s2]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> vect;
    int m, n, t;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << s.maxEqualRowsAfterFlips(matrix) << endl;
}