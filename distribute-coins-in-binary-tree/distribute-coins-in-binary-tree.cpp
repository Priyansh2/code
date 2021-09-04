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
    int solve(TreeNode* root, int &ans){
        if(!root) return 0;
        auto left_excess = solve(root->left,ans);
        auto right_excess = solve(root->right,ans);
        //ans+=abs(left_excess) + abs(right_excess);
        auto root_excess = root->val - 1 + left_excess + right_excess;
        ans+=abs(root_excess);
        return root_excess;
    }
    int distributeCoins(TreeNode* root) {
        //minimum moves at root is equal to sum of those of left and right subtree.
        //Each node will pass the excess amount. 
        int ans=0;
        auto p =solve(root,ans);
        return ans;
    }
};