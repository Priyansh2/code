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
    int val;
    bool solve(TreeNode *root){
        if(!root) return true;
        return root->val==val && solve(root->left) && solve(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        val = root->val;
        return solve(root);
    }
};