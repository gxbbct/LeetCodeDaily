#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int Sta1 = (event1[0][0] - '0') * 1000 + (event1[0][1] - '0') * 100 +
                   (event1[0][3] - '0') * 10 + (event1[0][4] - '0');
        int End1 = (event1[1][0] - '0') * 1000 + (event1[1][1] - '0') * 100 + 
                   (event1[1][3] - '0') * 10 + (event1[1][4] - '0');
        int Sta2 = (event2[0][0] - '0') * 1000 + (event2[0][1] - '0') * 100 + 
                   (event2[0][3] - '0') * 10 + (event2[0][4] - '0');
        int End2 = (event2[1][0] - '0') * 1000 + (event2[1][1] - '0') * 100 + 
                   (event2[1][3] - '0') * 10 + (event2[1][4] - '0');
        if ((Sta1 < Sta2 && End1 >= Sta2 && End1 <= End2) ||
        (Sta1 >= Sta2 && End1 <= End2) || (Sta1 >= Sta2 && Sta1 <= End2 && End1 > End2) ||
        (Sta1 <= Sta2 && End1 >= End2)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    vector<string> event1, event2;
    string t;
    cin >> t;
    event1.push_back(t.substr(0,5));
    event1.push_back(t.substr(6,5));
    cin >> t;
    event2.push_back(t.substr(0,5));
    event2.push_back(t.substr(6,5));
    cout << s.haveConflict(event1, event2) << endl;
}