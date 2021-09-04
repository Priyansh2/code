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
    TreeNode * solve(vector<int >& pre, vector<int> &post, int s, int e, int &p){
        if(s>e) return nullptr;
        auto root= new TreeNode(pre[p]);
        p++;
        if(s==e) return root;
        int pos = mp[pre[p]];
        root->left = solve(pre,post,s,pos,p);
        root->right = solve(pre,post,pos+1,e-1,p);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int s= 0, e = n-1,p=0;
        for(int i =0;i<n;i++) mp[postorder[i]] = i;
        return solve(preorder,postorder,s,e,p);
    }
};