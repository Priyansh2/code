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
    void swap(node * t1, node * t2){
        int t = t1->val;
        t1->val = t2->val;
        t2->val = t;
    }
    node * first, *middle, *last, *prev;
    void solve(node * root){
        if(!root) return;
        solve(root->left);
        
        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = first = middle = last = nullptr;
        solve(root);
        if(first && last) swap(first,last);
        else if (first && middle) swap(first,middle);
        
    }
};