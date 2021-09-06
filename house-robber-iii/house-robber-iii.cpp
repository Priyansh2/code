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
    unordered_map<TreeNode*, unordered_map<bool,int>> dp;
    int solve(TreeNode * root, bool incl){
        if(!root) return 0;
        if(dp.find(root)!=dp.end() && dp[root].find(incl)!=dp[root].end()) return dp[root][incl];
        int ans;
        if(incl){
            ans = root->val + solve(root->left,false) + solve(root->right,false);
        }
        else{
            ans = max(solve(root->left,false),solve(root->left,true)) + max(solve(root->right,false),solve(root->right,true));
        }
        return dp[root][incl] = ans; 
    }
    int rob(TreeNode* root) {
        return max(solve(root,true),solve(root,false));
    }
};