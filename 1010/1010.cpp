#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
找余数加起来可以等于60的对子。
处理两个特殊情况，余数都等于0以及余数都等于30。
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (int t : time) {
            cnt[t % 60]++;
        }
        int res = 0;
        for (int i = 1; i < 30; ++i) {
            res += cnt[i] * cnt[60-i];
        }
        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
        return res;
    }
};

int main() {
    Solution s;
    vector<int> time;
    int tmp;
    while (cin>>tmp) {
        time.push_back(tmp);
        if (cin.get() == '\n') {
            break;
        }
    }
    //
    cout << s.numPairsDivisibleBy60(time) << endl;
}