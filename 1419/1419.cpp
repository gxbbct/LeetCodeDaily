#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 这个版本会超时，因为需求是遍历已有的字符产生的，实际上需求可以用统计字母表的方式给出 */
/*
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> cnt;
        vector<int> plusok;
        int finish = 0;
        int n = 0;
        string ref = "croak";
        for (int i = 0; i < croakOfFrogs.size(); ++i) {
            if (croakOfFrogs[i] == ref[0]) {
                if (finish == 0) {
                    plusok.push_back(1);
                } else {
                    --finish;
                    plusok.push_back(0);
                }
                cnt.push_back(1);
            } else {
                int flag = 0;
                for (int j = 0; j < cnt.size(); ++j) {
                    if (croakOfFrogs[i] == ref[cnt[j]]) {
                        flag = 1;
                        ++cnt[j];
                        if (cnt[j] == 5) {
                            if (plusok[j]) {
                                ++n;
                            }
                            ++finish;
                            cnt.erase(cnt.begin()+j);
                            plusok.erase(plusok.begin()+j);
                        }
                        break;
                    }
                }
                if (!flag) {
                    return -1;
                }
            }
        }
        if (cnt.size() != 0) {
            return -1;
        } else {
            return n;
        }
    }
};
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> demand = {0,0,0,0,0};
        unordered_map<char,int> mp = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        int frog_on = 0;
        int frog_off = 0;
        string ref = "croak";
        for (int i = 0; i < croakOfFrogs.size(); ++i) {
            if (croakOfFrogs[i] == 'c') {
                ++frog_on;
                if (frog_off) {
                    --frog_off;
                }
                ++demand[1];
            } else {
                int idx = mp[croakOfFrogs[i]];
                if(--demand[idx] < 0) {
                    return -1;
                }
                if (idx == 4) {
                    --frog_on;
                    ++frog_off;
                } else {
                    ++demand[idx+1];
                }

            }
        }
        for (auto c:demand) {
            if (c) {
                return -1;
            }
        }
        return frog_off+frog_on;
    }
};

int main() {
    Solution s;
    string croakOfFrogs = "croakcroak";
    cout << s.minNumberOfFrogs(croakOfFrogs) << endl;
}