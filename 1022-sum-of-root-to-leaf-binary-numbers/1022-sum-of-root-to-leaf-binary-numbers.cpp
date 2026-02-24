/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, string str, int &ans) {
        str = str + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans += stoi(str, nullptr, 2);
            return;
        }
        if (root->left != NULL)
            solve(root->left, str, ans);
        if (root->right != NULL)
            solve(root->right, str, ans);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root, "", ans);
        return ans;
    }
};