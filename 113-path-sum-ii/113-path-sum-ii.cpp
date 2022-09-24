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
private:
    void path(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &curr)
    {
        if(root==NULL)
        {
            return;
        }
        curr.push_back(root->val);
        targetSum-=root->val;
        if(targetSum==0 && root->left==NULL && root->right==NULL)
        {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        path(root->left,targetSum,ans,curr);
        path(root->right,targetSum,ans,curr);
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        path(root,targetSum,ans,curr);
        return ans;
    }
};