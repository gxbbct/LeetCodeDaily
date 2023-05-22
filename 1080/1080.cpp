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


class Solution {
public:
    bool checkSufficientLeaf(TreeNode* node, int sum, int limit) {
        if (!node) {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node->val + sum >= limit;
        }
        bool haveSufficientLeft = checkSufficientLeaf(node->left, sum + node->val, limit);
        bool haveSufficientRight = checkSufficientLeaf(node->right, sum + node->val, limit);
        if (!haveSufficientLeft) {
            node->left = nullptr;
        }
        if (!haveSufficientRight) {
            node->right = nullptr;
        }
        return haveSufficientLeft || haveSufficientRight;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool haveSufficient = checkSufficientLeaf(root, 0, limit);
        return haveSufficient ? root : nullptr;
    }
};

TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    TreeNode* root = nullptr;
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode* node = nullptr;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    // 在根据这个规则去填充树的值的时候，如果该节点是nullptr，那么它的left和right都不用输入到数组中，leetcode上的输入就是这样的
    int nullcnt = 0;
    for (int i = 0; (i-nullcnt) * 2 + 2 < vec.size(); ++i) {
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[(i-nullcnt) * 2 + 1];
            vecTree[i]->right = vecTree[(i-nullcnt) * 2 + 2];
        } else {
            ++nullcnt;
        }
    }
    return root;
}

void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (node != nullptr) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            } else {
                vec.push_back(-1);
            }
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<int> vec;
    int t, limit;
    while (cin >> t) {
        vec.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> limit;
    TreeNode* root = construct_binary_tree(vec);
    cout << "-------------------" << endl;
    print_binary_tree(root);
    cout << "-------------------" << endl;
    root = s.sufficientSubset(root, limit);
    print_binary_tree(root);
}