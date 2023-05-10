#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) {
            return 1;
        } else if (k % 2 == 0) {
            return -1;
        }
        int d = 1 % k;
        int n = 1;
        bool found = false;
        while (n <= k) {
            if (d == k) {
                found = true;
                break;
            }
            d = (d * 10) % k + 1;
            ++n;
        }
        if (found) {
            return n;
        }
        return -1;
    }
};

int main() {
    Solution s;
    int k;
    cin >> k;
    cout << s.smallestRepunitDivByK(k) << endl;
}