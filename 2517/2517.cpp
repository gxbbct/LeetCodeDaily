#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        int mid = 0;
        while (l < r) {
            mid = l + (r - l + 1) / 2;
            if (check(price, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    bool check(const vector<int> &price, int k, int tastiness) {
        int prev = INT_MIN / 2;
        int cnt = 0;
        for (int p : price) {
            if (p - prev >= tastiness) {
                ++cnt;
                prev = p;
            }
        }
        return cnt >= k ;
    }
};

int main() {
    Solution s;
    vector<int> price;
    int t;
    while (cin >> t) {
        price.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    int k;
    cin >> k;
    cout << s.maximumTastiness(price, k) << endl;
}