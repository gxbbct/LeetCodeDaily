#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        int res = 0;
        int fill = 0;
        unordered_map<int, int> cnt;
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) idx[i] = i; // 可以用iota(idx.begin(), idx.end(), 0)代替， #include <numeric>
        sort(idx.begin(), idx.end(), [&](int a, int b){return values[a] > values[b];});
        for (int i = 0; i < n; ++i) {
            if (cnt[labels[idx[i]]] < useLimit) {
                res += values[idx[i]];
                ++cnt[labels[idx[i]]];
                if (++fill == numWanted) break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> values, labels;
    int numWanted, useLimit, t;
    while (cin >> t) {
        values.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    while (cin >> t) {
        labels.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> numWanted >> useLimit;
    cout << s.largestValsFromLabels(values, labels, numWanted, useLimit) << endl;
}