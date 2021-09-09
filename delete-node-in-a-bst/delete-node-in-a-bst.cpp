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
    TreeNode * get_pred(TreeNode * root){
        auto curr =root->left;
        while(curr && curr->right) curr = curr->right;
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val < key){
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        if(!root->left && !root->right){
            delete(root);
            return nullptr;
        }
        if(!root->left){
            auto t = root->right;
            delete(root);
            return t;
        }
        if(!root->right){
            auto t = root->left;
            delete(root);
            return t;
        }
        auto pred = get_pred(root);
        root->val = pred->val;
        root->left = deleteNode(root->left, pred->val);
        return root;
        
    }
};