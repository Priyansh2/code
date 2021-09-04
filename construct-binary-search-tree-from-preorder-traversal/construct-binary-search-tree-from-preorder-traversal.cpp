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
    TreeNode * construct_tree(int start,int end, int &pre_index, vector<int> pre,unordered_map<int,int>& mp){
        if(start >end) return NULL;
        TreeNode *root = new TreeNode(pre[pre_index]);
        int in_index  = mp[pre[pre_index]];
        pre_index++;
        root->left = construct_tree(start,in_index-1,pre_index,pre,mp);
        root->right = construct_tree(in_index+1,end,pre_index,pre,mp);
        return root;
    }
    TreeNode* naive_sol(vector<int> &preorder){
        // O(nlogn) & O(n)
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int n = inorder.size();  
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++) mp[inorder[i]]=i;
        int start=0, end =n-1, pre_index=0;
        return construct_tree(start,end,pre_index,preorder,mp);
    }
    TreeNode * build_bst(vector<int> &pre, int &idx, int mine, int maxe){
        if(idx >= pre.size() || pre[idx] <= mine || pre[idx] >= maxe) return NULL;
        TreeNode * root= new TreeNode(pre[idx]);
        idx++;
        root->left = build_bst(pre,idx,mine,root->val);
        root->right = build_bst(pre,idx,root->val,maxe);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        int mine  = INT_MIN , maxe = INT_MAX;
        return build_bst(preorder,idx,mine,maxe);
    }
};