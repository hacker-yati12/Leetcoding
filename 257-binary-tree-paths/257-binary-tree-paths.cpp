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
    vector<string> v;
    public:
vector<string> binaryTreePaths(TreeNode* root) {

    if(root && !root->left && !root->right) 
        return {to_string(root->val)};
    
    
    allPaths(root,v,"");
    return v;    
}
private:
void allPaths(TreeNode* root, vector<string> &ans, string s){

    s += to_string(root->val);
    if(root->left || root->right) 
        s += "->";
    if(!root->left && !root->right) 
        v.push_back(s);

    if(root->left) allPaths(root->left, v,s);
    if(root->right) allPaths(root->right, v,s);        
    
    s.pop_back();
    s.pop_back();
}

};