#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int help(vector<int>& nums, int firstLen, int secondLen) {
        int suml = accumulate(nums.begin(), nums.begin() + firstLen, 0); // accumulate区间: [a,b)
        int maxSumL = suml;
        int sumr = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int res = maxSumL + sumr;
        for (int i = firstLen + secondLen, j = firstLen; i < nums.size(); ++i, ++j) {
            suml += nums[j] - nums[j - firstLen];
            maxSumL = max(maxSumL, suml);
            sumr += nums[i] - nums[i - secondLen];
            res = max(res, maxSumL + sumr);
        }
        return res;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen));
    }
};

int main(){
    Solution s;
    vector<int> nums;
    int t;
    int firstLen = 0, secondLen = 0;
    while(cin >> t) {
        if (cin.get()!='\n') {
            nums.push_back(t);
        } else {
            cin >> firstLen >> secondLen;
            break;
        }
    }
    cout << s.maxSumTwoNoOverlap(nums,firstLen,secondLen) << endl;
}