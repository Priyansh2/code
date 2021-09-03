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
    vector<int> res;
    void solve(TreeNode *root){
        if(!root) return;
        if(!root->left && !root->right) res.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        res.clear();
        solve(root1);
        auto s1 = res;
        res.clear();
        solve(root2);
        if(s1.size()!=res.size()) return false;
        for(int i = 0;i<res.size();i++){
            if(s1[i]!=res[i]) return false;
        }
        return true;
    }
};