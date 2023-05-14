#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// 思路一： 统计频次，每次相邻的都放不同的(每次都放队列的头部)，放完以后频次减一并把该数字移到队列的尾部。
/*class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int b : barcodes) {
            count[b]++;
        }
        priority_queue<pair<int, int>> q;
        for (const auto &[x, cx] : count) {
            q.push({cx, x});
        }
        vector<int> res;
        while (q.size()) {
            auto [cx, x] = q.top();
            q.pop();
            if (res.empty() || res.back() != x) {
                res.push_back(x);
                if (cx > 1) {
                    q.push({cx - 1, x});
                }
            } else {
                if (q.size() < 1) return res;
                auto [cy, y] = q.top();
                q.pop();
                res.push_back(y);
                if (cy > 1)  {
                    q.push({cy - 1, y});
                }
                q.push({cx, x});
            }
        }
        return res;
    }
};*/


// 思路二：两次遍历，第一次从左到右遍历，看下有没有相邻相等的，有就向后找不相等的交换位置；第二次从右到左，同样的做法。

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        for (int i = 0; i < barcodes.size() - 1; ++i) {
            if (barcodes[i] == barcodes[i + 1]) {
                for (int j = i + 1; j < barcodes.size(); ++j) {
                    if (barcodes[j] != barcodes[i+1]) {
                        swap(barcodes[i + 1], barcodes[j]);
                        break;
                    }
                }
            }
        }
        for (int i = barcodes.size() - 1; i > 0; --i) {
            if (barcodes[i] == barcodes[i - 1]) {
                for (int j = i - 1; j >= 0; --j) {
                    if (barcodes[j] != barcodes[i - 1]) {
                        swap(barcodes[i - 1], barcodes[j]);
                        break;
                    }
                }
            }
        }
        return barcodes;
    }
};

int main() {
    Solution s;
    int t;
    vector<int> barcodes;
    while (cin >> t) {
        barcodes.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    vector<int> res;
    res = s.rearrangeBarcodes(barcodes);
    for (auto const &c : res) cout << c << " ";
    cout << endl;
}