#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/next-permutation/
// 1) 从后往前，找到n[i]<n[i+1]，记a=i;
// 2) 从后往前，找到n[a]<n[j], 记b=j;
// 3) 交换n[a]和n[b]，如果1)没找到，那么不用进行3)。
// 4) 把n[a+1]到n[end]变为升序，可以得到下一个全排列。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a = -1, b = nums.size();
        for (int i = b-1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                a = i-1;
                for (int j = b-1; j >= i; --j) {
                    if (nums[j] > nums[a]) {
                        b = j;
                        break;
                    }
                }
                break;
            }
        }
        if (a != -1) {
            int t = nums[b];
            nums[b] = nums[a];
            nums[a++] = t;
        } else {
            a = 0;
        }
        sort(nums.begin()+a, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums{1,5,1};
    s.nextPermutation(nums);
    for (auto a:nums) cout << a << " ";
    cout << endl;
}

// 同理可以用同样的手段解题https://leetcode.cn/problems/permutations-ii/
/*
class Solution {
public:
    vector<int> nextPermutation(vector<int> nums) {
        int a = -1, b = nums.size();
        for (int i = b-1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                a = i-1;
                for (int j = b-1; j >= i; --j) {
                    if (nums[j] > nums[a]) {
                        b = j;
                        break;
                    }
                }
                break;
            }
        }
        if (a != -1) {
            int t = nums[b];
            nums[b] = nums[a];
            nums[a++] = t;
        } else {
            a = 0;
        }
        sort(nums.begin()+a, nums.end());
        return nums;
    }
    bool cmpvec(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp = nextPermutation(nums);
        vector<vector<int>> res;
        res.emplace_back(tmp);
        while(!cmpvec(tmp,nums)){
            tmp = nextPermutation(tmp);
            res.emplace_back(tmp);
        }
        return res;
    }
};
*/