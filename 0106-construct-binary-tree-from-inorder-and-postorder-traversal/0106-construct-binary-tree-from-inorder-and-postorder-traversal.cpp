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
    TreeNode* buildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, 
        unordered_map<int, int>& mp) {
        if(instart>inend || poststart>postend)
            return nullptr;
        TreeNode* curr = new TreeNode(postorder[postend]);
        int mid = mp[curr->val];
        int left_el = mid - instart;
        curr->left = buildTree(inorder, instart, mid-1, postorder, poststart, poststart+left_el-1, mp);
        curr->right = buildTree(inorder, mid+1, inend, postorder, poststart+left_el, postend-1, mp);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};