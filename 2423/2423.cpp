#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        int num[26];
        memset(num,0,sizeof(num));
        int cnt = 0;
        int cntmin = 0;
        for (int i = 0; i < word.length(); ++i) {
            ++num[word[i]-'a'];
            if (num[word[i]-'a'] == 1) {
                ++cnt;
            }
        }
        sort(num,num+26);
        bool flag = true;
        if (num[25] == 1 || num[24] == 0 || cnt == 2 && num[24] == 1) {
            return true;
        } else if (num[24] == num[25]-1) {
            for (int i = 24; i > 25-cnt+1;) {
                if (num[i] != num[--i]) {
                    flag = false;
                    break;
                }
            }
        } else if (num[25-cnt+1] < num[25-cnt+2] && num[25-cnt+1] == 1) {
            for (int i = 25-cnt+2; i <= 24;) {
                if (num[i] != num[++i]) {
                    flag = false;
                    break;
                }
            }
        } else {
            flag = false;
        }
        return flag;
    }
};

int main(){
    Solution s;
    string word;
    cin >> word;
    cout << s.equalFrequency(word) << endl;
}