#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>


using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        dict.erase(beginWord);

        unordered_map<string, int> steps = {{beginWord, 0}};
        unordered_map<string, set<string>> from = {{beginWord,{}}};
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{{beginWord}};
        int wordLen = beginWord.length();
        while(!q.empty()) {
            ++step;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                for (int j = 0; j < wordLen; ++j) {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (steps[nextWord] == step) {
                            // 以免下一行在dict里面找不到nextword(之前出现过同样的nextword)而忽略了这一个currword
                            from[nextWord].insert(currWord); 
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        dict.erase(nextWord);
                        q.push(nextWord);
                        from[nextWord].insert(currWord);
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            vector<string> Path = {endWord};
            backtrack(res, endWord, from, Path);
        }
        return res;
    }
    
    void backtrack(vector<vector<string>> &res, const string &Node, unordered_map<string,set<string>> &from, vector<string> &path) {
        if (from[Node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string &Parent: from[Node]) {
            path.push_back(Parent);
            backtrack(res, Parent, from, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    string beginWord, endWord;
    vector<string> wordList;
    cin >> beginWord >> endWord;
    cin.get();
    string tmp;
    while (cin >> tmp) {
        wordList.push_back(tmp);
        if (cin.get() == '\n') {
            break;
        }
    }
    vector<vector<string>> res;
    res = s.findLadders(beginWord, endWord,wordList);
    cin.get();
}