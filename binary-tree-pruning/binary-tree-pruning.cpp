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
    void delete_all(TreeNode * root){
        if(!root) return;
        delete_all(root->left);
        delete_all(root->right);
        delete(root);
    }
    bool check(TreeNode *root){
        if(!root) return true;
        if(root->val==1) return false;
        return check(root->left) && check(root->right);
    }
    void solve(TreeNode *root, TreeNode *parent, bool isleft = true ){
        if(!root) return;
        if(check(root)){
            if(isleft) parent->left = NULL;
            else parent->right = NULL;
            //delete_all(root);
            return;
        }
        solve(root->left ,root,true);
        solve(root->right,root,false);
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* newroot = new TreeNode(-1,root,NULL);
        solve(root,newroot);
        return root= newroot->left;
    }
};