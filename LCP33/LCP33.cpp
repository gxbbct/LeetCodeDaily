#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int mx = *max_element(vat.begin(), vat.end());
        if (mx == 0) {
            return 0;
        }
        int ans = 1 << 30;
        int n = bucket.size();
        for (int x = 1; x <= mx; ++x) {
            int y = 0;
            for (int i = 0; i < n; ++i) {
                y += max(0, (vat[i] + x - 1) / x - bucket[i]);
            }
            ans = min(ans, x + y);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> bucket;
    vector<int> vat;
    int t;
    while (cin >> t) {
        bucket.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    while (cin >> t) {
        vat.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << s.storeWater(bucket, vat) << endl;
}