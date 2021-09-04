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
    unordered_map<int,int> mp;
        TreeNode * solve(vector<int> &preorder, vector<int> & inorder, int s, int e, int & p){
            if(s>e) return NULL;
            int root_idx = mp[preorder[p]];
            auto root = new TreeNode(preorder[p]);
            p++;
            root->left = solve(preorder,inorder,s,root_idx-1,p);
            root->right = solve(preorder,inorder,root_idx+1,e,p);
            return root;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        int n = inorder.size();
        for(int i = 0;i<n;i++) mp[inorder[i]] = i;
        int s = 0, e  = n-1, p = 0;
        return solve(preorder,inorder,s,e,p);
    }
};