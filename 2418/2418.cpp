#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        int maxid = 0;
        int tmpint;
        string tmpstr;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (heights[i] < heights[j]) {
                    tmpint = heights[j];
                    heights[j] = heights[i];
                    heights[i] = tmpint;
                    tmpstr = names[j];
                    names[j] = names[i];
                    names[i] = tmpstr; 
                }
            }
        }
        return names;
    };
    void ShowResult(vector<string>& names) {
        for (int i = 0; i < names.size(); ++i) {
            cout << names[i] << " ";
        }
        cout << endl;
    };
};

int main(){
    Solution s;
    vector<string> names{"Mary","John","Emma"};
    vector<int> heights{180,165,170};
    names = s.sortPeople(names, heights);
    s.ShowResult(names);
}