#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                res.push_back(nums[i]);
            }
        }
        int rn = res.size();
        for (int n = 0; n < nums.size() - rn; ++n) {
            res.push_back(0);
        }
        return res;
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
    nums = s.applyOperations(nums);
    for (auto & c : nums) cout << c << " ";
    cout << endl;
}