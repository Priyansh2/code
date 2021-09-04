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
    int maxcnt;
    node * prev;
    vector<int> res;
    void solve(node * root, int &cnt, bool fl){
        if(!root) return;
        solve(root->left, cnt,fl);
        if(!prev) {
            cnt=1;
        }
        else{
            if(prev->val==root->val) cnt++;
            else cnt =1;
        }
        if(fl){
            //fill in vector
            if(cnt==maxcnt) res.push_back(root->val);
        }
        else{
          maxcnt = max(maxcnt,cnt);  
        }
        prev = root;
        solve(root->right,cnt,fl);
        
    }
    vector<int> findMode(TreeNode* root) {
        maxcnt = 0;
        res.clear();
        prev = nullptr;
        int cnt =0;
        solve(root,cnt,false);
        cnt=0;
        solve(root,cnt,true);
        return res;
        
        
    }
};