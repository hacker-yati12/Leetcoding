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
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, 
        unordered_map<int, int>& mp) {
        if(prestart>preend || instart>inend)
            return nullptr;
        TreeNode* curr = new TreeNode(preorder[prestart]);
        int mid = mp[curr->val];
        int left_el = mid - instart;
        int right_el = inend - mid;
        curr->left = buildTree(preorder, prestart+1, prestart+left_el, inorder, instart, mid-1, mp);
        curr->right = buildTree(preorder, prestart+1+left_el, preend, inorder, mid+1, inend, mp);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]]=i;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};