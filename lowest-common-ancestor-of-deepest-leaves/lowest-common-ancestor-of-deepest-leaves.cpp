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
    int ht;
    int find_ht(node * root){
        if(!root) return -1;
        return max(find_ht(root->left),find_ht(root->right)) +1;
    }
    node * find_lca(node * root, int d){
        if(!root) return nullptr;
        if(d==ht) return root;
        auto left = find_lca(root->left,d+1);
        auto right = find_lca(root->right,d+1);
        if(left && right ) return root;
        return left ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ht = find_ht(root); 
        return find_lca(root,0);
    }
};