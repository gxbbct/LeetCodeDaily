#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            ++count[x];
        }
        int res = 0, n = nums.size(), t = 0;
        for (auto& [_, v] : count) {
            res += t * v * (n - t - v);
            t += v;
        }
        return res;
    }
};

int main() {
    Solution s;
    int t;
    vector<int> nums;
    while (cin >> t) {
        nums.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << s.unequalTriplets(nums) << endl;
}