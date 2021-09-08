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
    int maxlen;
    int solve(TreeNode * root){
        if(!root) return 0;
        auto left = solve(root->left);
        auto right = solve(root->right);
        if(root->left){
            if(root->val==root->left->val) left++;
            else left = 0;
        }
        if(root->right){ 
            if(root->val==root->right->val) right++;           
            else right = 0;
        }
        maxlen = max(maxlen, left + right);
        return max(left,right);
    }
    int longestUnivaluePath(TreeNode * root) {
        maxlen = 0;
        auto p = solve(root);
        return maxlen;
    }
};