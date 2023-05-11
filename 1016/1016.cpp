#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool help(const string& s, int k, int mi, int ma) {
        unordered_set<int> st;
        int t = 0;
        for (int r = 0; r < s.size(); ++r) {
            t = t * 2 + (s[r] - '0'); // 二进制转十进制
            if (r >= k) {
                t -= (s[r - k] - '0') << k;  // 弹出头字符，加入尾字符后数值
            }
            if (r >= k - 1 && t >= mi && t <= ma) {
                st.insert(t);
            }
        }
        return st.size() == ma - mi + 1;
    }

    bool queryString(string s, int n) {
        if (n == 1) {
            return s.find('1') != -1;
        }
        int k = 30;
        while ((1 << k) >= n) {
            --k;
        }
        if (s.size() < (1 << (k - 1)) + k - 1 || s.size() < n - (1 << k) + k + 1) {  // x<<y 对于二进制数为 x*(2^y)
            return false;
        }
        return help(s, k, 1 << (k - 1), (1 << k) - 1) && help(s, k + 1, 1 << k, n);
    }
};

int main() {
    string ss;
    Solution s;
    int n;
    cin >> ss;
    cin >> n;
    cout << s.queryString(ss, n) << endl;
}