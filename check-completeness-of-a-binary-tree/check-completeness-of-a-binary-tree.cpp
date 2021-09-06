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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int mark = -1;
        while(!q.empty()){
            int l = q.size();
            int cnt = 0;
            while(l--){
                auto p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                if(mark!=-1 && p->left && p->right) return false;
                if(mark!=-1 && !p->right && p->left) return false;
                
                if(!p->left || !p->right){
                    if(!p->left && p->right) return false;
                    if(mark==-1) mark = level;
                }
            }
            level++;
            //cout <<mark<< " "<<level<<endl;
            if(mark!=-1 && level - mark > 2) return false;
        }
        return true;
    }
};