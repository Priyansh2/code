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
    bool fl;
    void solve(TreeNode * &root, TreeNode * parent, int sib, vector<int> &voyage, int &p){
        
        if(!fl || !root) return;
        //cout <<root->val << " " << sib<<endl;
        if(root->val == voyage[p]) p++;
        else if (sib==voyage[p]){
            p++;
            res.push_back(parent->val);
            auto temp = parent->left;
            parent->left = parent->right;
            parent->right = temp;
        }
        else{
            fl = false;
        }
        int left = root->left ? root->left->val : -1;
        int right = root->right ? root->right->val : -1;
        solve(root->left,root,right,voyage,p);
        solve(root->right,root, left,voyage,p);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        res.clear();
        fl = true;
        int p =0;
        solve(root,nullptr, -1,voyage,p);
        if(!fl) return {-1};
        return res;
        
    }
};