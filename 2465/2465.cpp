#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> sum;
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (!sum.count(nums[i] + nums[n - i - 1])) {
                ++cnt;
                sum.insert(nums[i] + nums[n - i - 1]);
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int t;
    while (cin >> t) {
        nums.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << s.distinctAverages(nums) << endl;
}