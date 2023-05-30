#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode* node = nullptr;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
    }
    TreeNode* root = vecTree[0];
    for (int i = 0; i * 2 + 2 < vec.size(); ++i) {
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
};

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
};

// 不写递归的版本
class Solution1 {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delmp;
        for (auto& c : to_delete) delmp.insert(c);
        stack<TreeNode*> stk;
        stk.push(root);
        vector<TreeNode*> res;
        // 先判断根节点要不要删除
        if (!delmp.count(root->val)) {
            res.push_back(root);
        }
        while(!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            int addl, addr;
            // 判断左孩子是不是空
            TreeNode* tmp = cur->left;
            if (tmp != nullptr) {
                stk.push(tmp);
                // 判读左孩子要不要删除, addl = 1表示当前节点的左孩子具有被添加进res的潜力
                if (delmp.count(tmp->val)) {
                    cur->left = nullptr; // 断开当前节点和孩子的连接
                    addl = 0;
                } else {
                    addl = 1;
                }
            } else { // 空的时候无论什么情况也不会被添加进res
                addl = 0;
            }
            // 判断右孩子是不是空
            tmp = cur->right;
            if (tmp != nullptr) {
                stk.push(tmp);
                // 判读右孩子要不要删除, addr = 1表示当前节点的右孩子具有被添加进res的潜力
                if (delmp.count(tmp->val)) {
                    cur->right = nullptr;
                    addr = 0;
                } else {
                    addr = 1;
                }
            } else {
                addr = 0;
            }
            // 判断下当前节点是否需要被删除，如果被删除了，那就需要把潜在的可添加进res的孩子都添加进res
            if (delmp.count(cur->val)) {
                if (addl) {
                    res.push_back(cur->left);
                }
                if (addr) {
                    res.push_back(cur->right);
                }
            }
        }
        return res;
    }
};

// 写递归的版本
class Solution2 {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // unordered_set初始化的另一种方式
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> roots;

        function<TreeNode* (TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
            // 如果搜索到了尽头，就直接返回
            if (node == nullptr) {
                return nullptr;
            }
            // 判断当前节点是否需要被删除
            bool deleted = to_delete_set.count(node->val) ? true : false;
            // 更新左节点的值，实际上是在作深度优先搜索，从最左边搜到最右边
            node->left = dfs(node->left, deleted);
            // 更新右节点的值
            node->right = dfs(node->right, deleted);
            // 如果当前节点是被删除的，那么返回nullptr，也就是它上一个的left或者right会被置为nullptr，断开连接
            if (deleted) {
                return nullptr;
            } else { // 如果当前节点不会被删除，那么要看下它是否是根节点，也就是它的父节点是否被删除
                if (is_root) { // 父节点被删除，把当前节点添加进结果
                    roots.emplace_back(node);
                }
                return node; // 直接返回当前节点，等于什么也没做
            }
        };

        dfs(root, true);
        return roots;
    }
};


int main() {
    Solution1 s;
    // Solution2 s;
    vector<int> vec;
    int t;
    while (cin >> t) {
        vec.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    vector<int> to_delete;
    while (cin >> t) {
        to_delete.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    TreeNode* root;
    root = construct_binary_tree(vec);
    cout << "Original Tree:" << endl;
    print_binary_tree(root);
    vector<TreeNode*> res;
    res = s.delNodes(root, to_delete);
    cout << "Tree after Deleting Operation:" << endl;
    for (const auto& c : res) {
        cout << "----------" << endl;
        print_binary_tree(c);
    }
}