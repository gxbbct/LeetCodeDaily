#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> p(n + 1);
        if (n == 1) {
            return 1;
        } else {
            p[1] = 1;
        }
        if (n == 2) {
            return 2;
        } else {
            p[2] = 2;
        }
        for (int i = 3; i <=n; ++i) {
            p[i] = p[i - 1] + p[i - 2];
        }
        return p[n];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.climbStairs(n) << endl;
}