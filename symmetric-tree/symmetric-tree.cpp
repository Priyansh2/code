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
    bool solve1(node * r1, node *r2){
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        return r1->val==r2->val && solve1(r1->left,r2->right) && solve1(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve1(root,root);
        
    }
};