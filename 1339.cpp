#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
long long totalSum = 0;
long long maxProducts = 0;
static const int MOD = 1e9 + 7;
long long getTotalSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + getTotalSum(root->left) + getTotalSum(root->right);
}
long long dfs(TreeNode* root) {
    if (!root) return 0;

    long long leftSum = dfs(root->left);
    long long rightSum = dfs(root->right);

    long long subTreeSum = root->val + leftSum + rightSum;

    long long product = subTreeSum * (totalSum - subTreeSum);
    maxProducts = max(maxProducts, product);

    return subTreeSum;
}

int maxProduct(TreeNode* root) {
    totalSum = getTotalSum(root);
    dfs(root);
    return maxProducts % MOD;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << maxProduct(root) << endl;
    return 0;
}