#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        long long int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0 && nums[i] % 3 == 0) {
                ++cnt;
                sum += nums[i];
            }
        }
        if (cnt) {
            return sum / cnt;
        } else {
            return 0;
        }
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
    cout << s.averageValue(nums) << endl;
}