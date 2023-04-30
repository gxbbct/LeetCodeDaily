// https://leetcode.cn/problems/sum-of-square-numbers/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a*a <= c; ++a) {
            int b = c - a*a;
            if (b == pow((int)sqrt(b),2)) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    int c;
    cin >> c;
    cout << s.judgeSquareSum(c) << endl;
}