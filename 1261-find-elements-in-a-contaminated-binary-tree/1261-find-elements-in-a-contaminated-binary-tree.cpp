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
class FindElements {
public:
    unordered_set<int> st;
    void construct(TreeNode* root, int val){
        if(!root) return;
        if(root->left){
            root->left->val = 2*val+1;
            st.insert(root->left->val );
            construct(root->left, root->left->val);
        }
        
        if(root->right){
            root->right->val = 2*val+2;
            st.insert(root->right->val );
            construct(root->right, root->right->val);
        }
    }
    FindElements(TreeNode* root) {
        st.insert(0);
        construct(root, 0);
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */