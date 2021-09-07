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
    unordered_map<TreeNode*,int> ssum;
    long long tsum, m = 1e9+7;
    long long maxprod;
    int subtree_sum(TreeNode * root){
        if(!root) return 0;
        auto left = subtree_sum(root->left);
        auto right = subtree_sum(root->right);
        ssum[root] = root->val + left +right;
        return ssum[root];
    }
    void solve(TreeNode * root){
        if(!root || (!root->left && !root->right)) return;
        long long  prod;
        if(root->left){
            prod = ssum[root->left] * (tsum - ssum[root->left]);
            maxprod = max(maxprod, prod);
        }
        if(root->right){
            prod = ssum[root->right] * (tsum - ssum[root->right]);
            maxprod = max(maxprod, prod);
        }
        solve(root->left);
        solve(root->right);
        
    }
    int maxProduct(TreeNode* root) {
        tsum = subtree_sum(root);
        maxprod = LLONG_MIN;
        solve(root);
        return maxprod%m;
    }
};