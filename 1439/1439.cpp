#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int pre[k];
        int cur[mat[0].size() * k];
        memset(pre, 0, sizeof(pre));
        int size = 1;
        for (auto& row : mat) {
            int i = 0;
            for (int j = 0; j < size; ++j) {
                for (int& v : row) {
                    cur[i++] = pre[j] + v;
                }
            }
            sort(cur, cur + i);
            size = min(i, k);
            for (int j = 0; j < size; ++j) {
                pre[j] = cur[j];
            }
        }
        return pre[k-1];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> mat;
    for (int i = 0; i < n; ++i) {
        int t;
        vector<int> vect;
        while (cin >> t) {
            vect.push_back(t);
            if (cin.get() == '\n') {
                break;
            }
        }
        mat.push_back(vect);
    }
    int k;
    cin >> k;
    cout << s.kthSmallest(mat, k) << endl;
}