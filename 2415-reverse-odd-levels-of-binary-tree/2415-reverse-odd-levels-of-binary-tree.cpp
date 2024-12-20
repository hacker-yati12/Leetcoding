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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        vector<TreeNode*> lis;
        while(!empty(q)) {
            int sz = q.size();  
            ++level;          
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
                if(level%2 != 0) {
                    lis.push_back(node);
                }
            }
            if(level%2 != 0) {
                int left = 0, right = lis.size()-1;
                while(left<right) {
                    int temp = lis[left]->val;
                    lis[left]->val = lis[right]->val;
                    lis[right]->val = temp;
                    left++;
                    right--;
                }
                lis.clear();
            }
        }
        return root;
    }
};