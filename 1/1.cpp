#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {            
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                res[0] = i;
                res[1] = it->second;
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int t, target;
    while (cin >> t) {
        nums.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> target;
    vector<int> res;
    res = s.twoSum(nums, target);
    for (const auto& c : res) cout << c << " ";
    cout << endl;
}