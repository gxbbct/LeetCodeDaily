#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> cnt; // 新建哈希表，以字符为key, 索引为value，value表示以这个字符为结尾的词链的长度，最小为1
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             {
                 return a.size() < b.size(); // 将词组由当中字符串长度小到大排列
             });
        int res = 0;
        for (string word : words)
        {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); i++)
            {
                string prev = word.substr(0, i) + word.substr(i + 1); // 遍历词组，将当前字符串去除任意位
                if (cnt.count(prev))
                {
                    cnt[word] = max(cnt[word], cnt[prev] + 1); // 如果之前存在这样的子字符串，那么当前字符串可以和之前的组成词链，长度+1
                }
            }
            res = max(res, cnt[word]); // 更新词链最大长度
        }
        return res;
    }
};

int main()
{
    Solution s;
    string word;
    vector<string> words;
    while (cin >> word)
    {
        stringstream ss(word);
        string ts;
        while (getline(ss, ts, ','))
        {
            words.push_back(ts);
        };
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cout << s.longestStrChain(words) << endl;
}