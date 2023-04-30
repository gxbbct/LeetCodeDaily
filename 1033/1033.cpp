#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int t;
        vector<int> res;
        if (a > b) {
            t = b;
            b = a;
            a = t;
        }
        if (a > c) {
            t = c;
            c = a;
            a = t;
        }
        if (b > c) {
            t = c;
            c = b;
            b = t;
        }
        if (a + 1 == b && b + 1 == c) {
            res.emplace_back(0);
            res.emplace_back(0);
            return res;
        }
        int max_moves = c-a-2;
        if (b - a <= 2 || c - b <= 2) {
            res.emplace_back(1);
            res.emplace_back(max_moves);
        } else {
            res.emplace_back(2);
            res.emplace_back(max_moves);
        }
        return res;
    }
};

int main() {
    Solution s;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> res;
    res = s.numMovesStones(a,b,c);
    for (auto a:res) {
        cout << a << endl;
    }

}