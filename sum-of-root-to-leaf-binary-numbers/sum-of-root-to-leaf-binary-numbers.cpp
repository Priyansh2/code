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
    int ans;
    void solve(TreeNode * root, int res){
        if(!root) return;
        res = 2*res + root->val;
        if(!root->left && !root->right) ans+=res;
        solve(root->left,res);
        solve(root->right,res);
    }
    int sumRootToLeaf(TreeNode* root) {
         ans=0;
        solve(root,0);
        return ans;
    }
};