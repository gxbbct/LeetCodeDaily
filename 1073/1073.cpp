#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 主要考虑进位的可能性，由于是负数，所以可以进负一
// 可以参考答案里那个遍历完较长的那个数组的写法
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0;
        vector<int> ans;
        while (i >= 0 || j >= 0 || carry) {
            int x = carry;
            if (i >= 0) {
                x += arr1[i];
            }
            if (j >= 0) {
                x += arr2[j];
            }
            
            if (x >= 2) {
                ans.push_back(x - 2);
                carry = -1;
            }
            else if (x >= 0) {
                ans.push_back(x);
                carry = 0;
            }
            else {
                ans.push_back(1);
                carry = 1;
            }
            --i;
            --j;
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr1;
    vector<int> arr2;
    int t;
    while (cin >> t) {
        arr1.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    while (cin >> t) {
        arr2.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    vector<int> res;
    res = s.addNegabinary(arr1, arr2);
    for (int const& c : res) cout << c << " ";
    cout << endl;
}