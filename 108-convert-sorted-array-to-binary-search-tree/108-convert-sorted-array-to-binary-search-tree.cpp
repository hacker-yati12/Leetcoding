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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        TreeNode* root = heightBalancedTree(start , end , nums);
        return root;        
    }

    TreeNode* heightBalancedTree(int start ,int end ,vector<int>& nums)
    {
        if(start>end) 
            return NULL;
        int middle = start+(end-start)/2;
        TreeNode* createNode = new TreeNode(nums[middle]);    
        if(createNode == NULL) 
            return NULL;    
        if(start == end) 
            return createNode;
        createNode->left=heightBalancedTree(start,middle-1,nums);
        createNode->right=heightBalancedTree(middle+1,end,nums);    
        return createNode;
    }
};