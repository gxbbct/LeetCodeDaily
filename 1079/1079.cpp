#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        set<char> tile;  // 可以存放字母，且可以遍历，结合字母统计表用
        int n = tiles.length();
        for (char const& c : tiles) {
            ++count[c];
            tile.insert(c);
        }
        return dfs(count, tile, n) - 1;
    }

    int dfs(unordered_map<char, int>& count, set<char>& tile, int i) {
        if (i == 0) {
            return 1;  // 没得再探了，给当前组合计数
        }
        int res = 1; // 当前的组合计数，必须有，但是这个会导致最顶层是空白字符，所以会多记入一个空白字符
        for (char t : tile) {
            if (count[t] > 0) {
                count[t]--;
                res += dfs(count, tile, i - 1);  // 往下探索一层
                count[t]++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string tiles;
    cin >> tiles;
    cout << s.numTilePossibilities(tiles) << endl;
}