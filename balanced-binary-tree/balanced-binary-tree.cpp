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
    unordered_map<node * ,int > mp;
    int solve(TreeNode*root){
        //O(n) solution. Naive is O(n^2);
        if(!root) return -1;
        int lh = solve(root->left);
        if(lh==-2) return -2;
        int rh = solve(root->right);
        if(rh==-2) return -2;
        if(abs(lh-rh) > 1) return -2;
        return max(lh,rh) +1;
    }
    bool bottom_up(node * root){
        bool ans = true;
        auto p = solve(root);
        if (p==-2) return !ans;
        return ans;
    }
    
    int get_height(node *root){
        if(!root) return 0;
        int left = get_height(root->left);
        int right = get_height(root->right);
        return mp[root]= max(left,right) +1;
    }
    bool solve2(node *root){
        if(!root) return true;
        return abs(mp[root->left] - mp[root->right])<=1 && solve2(root->left) && solve2(root->right); 
    }
    bool top_down(node * root){
        mp.clear();
        auto ht = get_height(root);
        return solve2(root);
    }
    bool isBalanced(TreeNode* root) {
        //return bottom_up(root);
        return top_down(root);
        
    }
};