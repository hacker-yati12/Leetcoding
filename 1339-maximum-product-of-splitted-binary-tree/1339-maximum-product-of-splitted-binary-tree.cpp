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
public:
    long int total=0;
    long int all(TreeNode* root){
        if(!root){
            return 0;
        }
        total+=root->val;
        all(root->left);
        all(root->right);
        return total;
    }
    long int ans=0;
    long int dfs(TreeNode* root,long int &ans){
        if(!root){
            return 0;
        }
        long int sum=root->val+dfs(root->left,ans)+dfs(root->right,ans);
        if((total-sum)*sum>ans){
            ans=(total-sum)*sum;
        }
        return sum;
    }
    int maxProduct(TreeNode* root) {
        all(root);
        dfs(root,ans);
        return ans%1000000007;
    }
};