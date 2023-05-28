#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minnum = 0.0, maxnum = 0.0, meannum = 0.0, mediannum = 0.0, modenum = 0.0;
        int minFlag = 0, medianidx, a, b, medianFlag = 0, cnt = 0, maxcnt = 0;
        double sum;
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] != 0) {
                cnt += count[i];
                sum += (double)i * count[i];
                if (count[i] > maxcnt) {
                    modenum = i;
                    maxcnt = count[i];
                }
                maxnum = i;
                if (minFlag == 0) {
                    minnum = i;
                    minFlag = 1;
                }
            }
        }
        meannum = sum / (double)cnt;
        if (cnt % 2 != 0) {
            medianFlag = 1;
        }
        medianidx = cnt/2 - 1;
        cnt = 0;
        for (int i = 0; i < count.size(); ++i) {
            cnt += count[i];
            if (cnt - 1 >= medianidx) {
                a = i;
                if (cnt - 1 - medianidx > 0) {
                    b = i;
                } else {
                    for (int k = i + 1; k < count.size(); ++k) {
                        if (count[k] != 0) {
                            b = k;
                            break;
                        }
                    }
                }
                break;
            }
        }
        if (medianFlag) {
            mediannum = b;
        } else {
            mediannum = (a + b) / 2.0;
        }
        return {minnum, maxnum, meannum, mediannum, modenum};
    }
};

int main() {
    Solution s;
    vector<double> res;
    vector<int> count;
    int t;
    while (cin >> t) {
        count.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    res = s.sampleStats(count);
    for (auto& c : res) cout << c << " ";
    cout << endl;
}