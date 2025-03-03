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
    TreeNode* build(vector<int>& preorder, int s, int e) {
        if(s>e)
            return nullptr;
        TreeNode* curr = new TreeNode(preorder[s]);
        int node = curr->val;
        int left_el = upper_bound(preorder.begin()+s+1, preorder.begin()+e+1, node)-(preorder.begin()+s+1);
        curr->left = build(preorder, s+1, s+left_el);
        curr->right = build(preorder, s+left_el+1, e);
        return curr;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size()-1);
    }
};