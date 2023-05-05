#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<vector<int>> info;
        int endtime = 0;
        int maxtime = 0;
        for (int i = 0; i < logs.size(); ++i) {
            int tasktime = logs[i][1] - endtime;
            endtime = logs[i][1];
            vector<int> tmp;
            tmp.emplace_back(logs[i][0]);
            tmp.emplace_back(tasktime);
            info.emplace_back(tmp);
        }
        sort(info.begin(),info.end(),[](vector<int> a, vector<int> b) {
            return a[1] > b[1];
        });
        int minid = info[0][0];
        maxtime = info[0][1];
        info.erase(info.begin());
        while (info.size()) {
            int curid = info[0][0];
            if (curid <= minid && info[0][1] == maxtime) {
                minid = curid;
            } else if (info[0][1] < maxtime) {
                break;
            }
            info.erase(info.begin());
        }
        return minid;
    }
};*/

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int minid = n+1;
        int endtime = 0;
        int maxtime = 0;
        for (int i = 0; i < logs.size(); ++i) {
            int tasktime = logs[i][1] - endtime;
            endtime = logs[i][1];
            if (tasktime > maxtime) {
                maxtime = tasktime;
                minid = logs[i][0];
            } else if (tasktime == maxtime && logs[i][0] < minid) {
                minid = logs[i][0];
            }
        }
        return minid;
    }
};

int main() {
    vector<vector<int>> logs = {{0,3},{2,5},{0,9},{1,15}};
    int n = 10;
    Solution s;
    cout << s.hardestWorker(n,logs) << endl;
}