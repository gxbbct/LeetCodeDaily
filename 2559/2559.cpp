#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre;
        unordered_set<char> alphabet{'a','e','i','o','u'};
        pre.push_back(0);
        int cnt = 0;
        for (string& c : words) {
            if (alphabet.count(c[0]) &&alphabet.count(c[c.size() - 1])) {
                ++cnt;
            }
            pre.push_back(cnt);
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); ++i) {
            res.push_back(pre[queries[i][1] + 1] - pre[queries[i][0]]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words;
    string t;
    while (cin >> t) {
        words.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    int n;
    cin >> n;
    vector<vector<int>> queries(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> queries[i][j];
        }
    }
    vector<int> res;
    res = s.vowelStrings(words, queries);
    for (const auto& c : res) cout << c << " ";
    cout << endl;
}