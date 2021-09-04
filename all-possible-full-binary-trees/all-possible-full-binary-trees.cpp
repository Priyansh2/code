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
    TreeNode * get_clone(TreeNode * root)
    {
        if(!root) return NULL;
        auto newnode = new TreeNode(0);
        newnode->left = get_clone(root->left);
        newnode->right = get_clone(root->right);
        return newnode;
    }    
    vector<TreeNode*> solve(int n , unordered_map<int,vector<TreeNode*>>&dp){
        if(n%2==0) return dp[n] = {};
        if(n==1) return dp[n] = {new TreeNode(0)};
        if(dp.find(n)!=dp.end()) return dp[n];
        vector<TreeNode*> trees;
        for(int j = 0;j<n;j++){
            auto left_subtrees = solve(j,dp);
            auto right_subtrees = solve(n-1-j,dp);
            for(auto left: left_subtrees){
                for(auto right:right_subtrees){
                    auto root = new TreeNode(0);
                    root->left = get_clone(left);
                    root->right = get_clone(right);
                    trees.push_back(root);
                }
            }
        }
        return dp[n] = trees;
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        unordered_map<int, vector<TreeNode*> > dp;
        return solve(N,dp);
        
        
    }
};