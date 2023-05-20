// 关于Struct初始化的知识点见https://zhuanlan.zhihu.com/p/392077524
// 关于二叉树初始化知识点见https://blog.csdn.net/m0_47240785/article/details/123406393
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree(vec.size(), NULL);
    TreeNode* root = NULL;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 2 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

// 层序打印二叉树
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            } else { // 用-1表示NULL
                vec.push_back(-1);
            }
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int res;
    struct SubTree {
        bool isBST;
        int minValue;
        int maxValue;
        int sumValue;
        SubTree(bool isBST, int minValue, int maxValue, int sumValue) : isBST(isBST), minValue(minValue), maxValue(maxValue), sumValue(sumValue) {}
    };

    SubTree dfs(TreeNode* root) {
        if (root == nullptr) {
            return SubTree(true, inf, -inf, 0);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.isBST && right.isBST && 
                root->val > left.maxValue &&
                root->val < right.minValue) {
            int sum = root->val + left.sumValue + right.sumValue;
            res = max(res, sum);
            return SubTree(true, min(left.minValue, root->val), 
                             max(root->val, right.maxValue), sum);
        } else {
            return SubTree(false, 0, 0, 0);
        }
    }

    int maxSumBST(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> vec;
    int t;
    while (cin >> t) {
        vec.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    TreeNode* root = construct_binary_tree(vec);
    print_binary_tree(root);
    cout << s.maxSumBST(root) << endl;
}