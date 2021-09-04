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
    int maxdiff;
    
    void solve(TreeNode * root, int mine, int maxe){
        if(!root) return;
        mine = min(mine,root->val);
        maxe = max(maxe,root->val);    
        if(!root->left && !root->right){
            maxdiff = max(maxdiff , abs(mine - maxe));
        }
        solve(root->left,mine,maxe);
        solve(root->right,mine,maxe); 
    }
    int maxAncestorDiff(TreeNode* root) {
        maxdiff = INT_MIN;
        solve(root,INT_MAX,INT_MIN);
        return maxdiff;
    }
};