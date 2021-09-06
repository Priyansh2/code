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
    bool isEvenOddTree(TreeNode* root) {
        if( (root->val & 1) ==0) return false;
        queue <TreeNode*> q;
        q.push(root);
        int level = 1;
        bool fl = false;
        int maxe = INT_MAX, mine = INT_MIN;
        while(!q.empty()){
            int l = q.size();
            if(level & 1 ) {
                fl = true;
                maxe = INT_MAX;
            }
            else {
                fl = false;
                mine = INT_MIN;
            }
            while(l--){
                auto p = q.front();
                q.pop();
                if(fl){
                    if(p->left){
                        int val = p->left->val;
                        if(val &1) return false;
                        if(maxe  > val){
                            maxe = val;
                        }
                        else return false;
                        q.push(p->left);
                    }
                    if(p->right){
                        int val = p->right->val;
                        if(val & 1) return false;
                        if(maxe  > val){
                            maxe = val;
                        }
                        else return false;
                        q.push(p->right);
                    }
                }
                else{
                    if(p->left){
                        int val = p->left->val;
                        if((val &1) ==0) return false;
                        if(mine  < val){
                            mine = val;
                        }
                        else return false;
                        q.push(p->left);
                    }
                    if(p->right){
                        int val = p->right->val;
                        if((val & 1)==0) return false;
                        if(mine  < val){
                            mine = val;
                        }
                        else return false;
                        q.push(p->right);
                    }
                    
                }
            }
            //cout <<level << " ";
            level++;
        }
        return true;
    }
};