#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 1;
        int k = 0;
        while (j + k < n) {
            if (s[i+k] == s[j+k]) {
                ++k;
            } else if (s[i+k] < s[j+k]) {
                i = i + k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};

int main(){
    Solution s;
    string mys = "zrziy";
    cout << s.lastSubstring(mys) << endl;
}