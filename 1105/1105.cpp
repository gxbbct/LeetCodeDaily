#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> f(n+1, 1000000);
        f[0] = 0; 
        for(int i = 1; i<=n; ++i) {
            int cwidth = 0;
            int maxhgt = 0;
            for(int j = i; j>0; --j) {
                cwidth += books[j-1][0];
                if(cwidth > shelfWidth) {
                    break;
                }
                maxhgt = max(maxhgt, books[j-1][1]);
                f[i] = min(f[i], maxhgt+f[j-1]);
            }
        }
        return f[n];
    }
};

int main(){
    Solution s;
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << s.minHeightShelves(books, 4) << endl;
}