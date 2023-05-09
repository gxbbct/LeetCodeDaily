#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countTime(string time) {
        int k1 = 1, k2 = 1;
        if (time[0] == '?') {
            k1 = 3;
            if (time[1] == '?') {
                k1 = 24;
            } else if (time[1] >= '4') {
                k1 = 2;
            }
        } else {
            if (time[1] == '?') {
                if (time[0] <= '1') {
                    k1 = 10;
                } else {
                    k1 = 4;
                }
            }
        }
        if (time[3] == '?') {
            k2 = 6;
            if (time[4] == '?') {
                k2 = 60;
            }
        } else {
            if (time[4] == '?') {
                k2 = 10;
            }
        }
        return k1*k2;
    }
};

int main() {
    Solution s;
    string ss;
    cin >> ss;
    cout << s.countTime(ss) << endl;
}