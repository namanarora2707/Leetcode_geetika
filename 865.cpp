#include <bits/stdc++.h>
using namespace std;
pair<TreeNode*, int> dfs(TreeNode* root) {
    if (!root) return {nullptr, 0};

    auto left = dfs(root->left);
    auto right = dfs(root->right);
    if (left.second == right.second) {
        return {root, left.second + 1};
    }
    else if (left.second > right.second) {
        return {left.first, left.second + 1};
    }
    else {
        return {right.first, right.second + 1};
    }
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return dfs(root).first;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* result = subtreeWithAllDeepest(root);
    cout << result->val << endl;
    return 0;
}