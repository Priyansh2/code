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
    bool fl;
    void solve(TreeNode * root, long  l, long r){
        if(!root || !fl ) return;
        if(root->val < l || root->val > r) {
            fl = false;
            return;
        }
        solve(root->left,l,(long)root->val-1);
        solve(root->right,(long)root->val+1,r);
    }
    bool isValidBST(TreeNode* root) {
        fl = true;
        solve(root, LONG_MIN, LONG_MAX);
        return fl;
    }
};