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
#define node TreeNode
class Solution {
public:
    int ans;
    void solve(node * root, int low, int high){
        if(!root)return;
        if(root->val <=high && root->val >=low) {
            ans+=root->val;
            solve(root->left,low,high);
            solve(root->right,low,high);
        }
        else if (root->val < low) solve(root->right,low,high);
        else solve(root->left,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans=0;
        solve(root,low,high);
        return ans;
    }
};