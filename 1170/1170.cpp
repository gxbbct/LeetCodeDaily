#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freq(12), res;
        for (int i = 0; i < words.size(); ++i) {
            ++freq[fs(words[i])];
        }
        for (int i = freq.size() - 2; i >=0; --i) {
            freq[i] = freq[i + 1] + freq[i];
        }
        for (int i = 0; i < queries.size(); ++i) {
            int curfreq = fs(queries[i]);
            res.push_back(freq[curfreq + 1]);
        }
        return res;
    }
    
    int fs(string &s) {
        int cnt = 0, idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == s[idx]) {
                ++cnt;
            } else if (s[i] < s[idx]) {
                idx = i;
                cnt = 1;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    int n, m;
    cin >> n;
    string t;
    vector<string> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i];
    }
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<int> res;
    res = s.numSmallerByFrequency(queries, words);
    for (const int& c : res) cout << c << " ";
    cout << endl;
}