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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()) {
            int sz = q.size();
            int curr = 0;
            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                curr += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(curr > sum) {
                ans = level;
                sum = curr;
            }
            level++;
        }
        return ans;
    }
};