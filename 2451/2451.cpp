#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        vector<int> ref;
        for (int i = 1; i < words[0].size(); ++i) {
            ref.push_back(words[0][i] - words[0][i-1]);
        }
        for (int i = 1; i < words.size(); ++i) {
            for (int j = 1; j < words[i].size(); ++j) {
                if (words[i][j] - words[i][j - 1] != ref[j - 1]) {
                    if (i == 1) {
                        int flag = 0;
                        for (int k = 1; k < words[i].size(); ++k) {
                            if (words[i + 1][k] - words[i + 1][k - 1] != ref[k - 1]) {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag) {
                            return words[0];
                        } else {
                            return words[i];
                        }
                    } else {
                        return words[i];
                    }
                }
            }
        }
        return words[0];
    }
};

int main() {
    Solution s;
    vector<string> words;
    string mys;
    cin >> mys;
    stringstream ss(mys);
    while (getline(ss, mys, ',')) words.push_back(mys);  // 输入为：aaa,bob,ccc,ddd  逗号隔开，不要加空格
    string res;
    res = s.oddString(words);
    cout << res << endl;
}