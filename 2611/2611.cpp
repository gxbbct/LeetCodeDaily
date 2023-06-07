#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> t(n);
        vector<int> ind(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
            t[i] = reward1[i] - reward2[i];
            sum += reward2[i];
        }
        sort(ind.begin(), ind.end(), [&] (int x, int y) {
            return t[x] > t[y];
        });
        for (int i = 0; i < k; ++i) {
            sum += t[ind[i]];
        }
        return sum;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> reward1(n), reward2(n);
    for (int i = 0; i < n; ++i) {
        cin >> reward1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> reward2[i];
    }
    int k;
    cin >> k;
    cout << s.miceAndCheese(reward1, reward2, k) << endl;
}