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
    int cnt;
    void solve(TreeNode * root, int maxe ){
        if(!root) return;
        if(maxe <=root->val) cnt++;
        solve(root->left, max(maxe,root->val));
        solve(root->right,max(maxe,root->val));
        
    }
    int goodNodes(TreeNode* root) {
        int maxe = INT_MIN;
        cnt = 0;
        solve(root,maxe);
        return cnt;
    }
};