#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cmp = 0;
        int res = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[cmp] > 0 || cmp == i) {
                break;
            } else if (nums[i] + nums[cmp] > 0) {
                continue; 
            } else if (nums[i] + nums[cmp] < 0) {
                ++cmp;
                ++i;
            } else {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int t;
    while (cin>>t) {
        nums.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << s.findMaxK(nums) << endl;
}