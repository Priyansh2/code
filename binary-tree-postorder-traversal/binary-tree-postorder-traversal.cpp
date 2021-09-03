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
    void solve(TreeNode*root, vector<int>&res){
        if(!root) return;
        solve(root->left,res);
        solve(root->right,res);
        res.push_back(root->val);
        
    }
    void ite_solve(TreeNode* root,vector<int>&res){
        stack<TreeNode*> st;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                res.push_back(root->val);
                root = root->right;
            }
            else {
                root = st.top();
                st.pop();
                root = root->left;
            }
        }
        reverse(res.begin(),res.end());
        return;
    }
    void ite_solve2(TreeNode* root,vector<int>&res){
        stack<TreeNode*> st;
        TreeNode* prev = NULL;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                auto temp = st.top();
                if(temp->right && temp->right!=prev) root = temp->right;
                else {
                    res.push_back(temp->val);
                    prev = temp;
                    st.pop();
                }
            }
        }
        return;
    }
    TreeNode * inorder_pred(TreeNode* root){
        TreeNode* pred = root->right;
        while(pred->left && pred->left!=root){
            pred = pred->left;
        }
        return pred;
    }
    void morris_traversal(TreeNode* root, vector<int>&res){
        if(!root) return;
        while(root){
            if(!root->right){
                res.push_back(root->val);
                root = root->left;
            }
            else {
                auto pred = inorder_pred(root);
                if(!pred->left){
                    pred->left = root;
                    res.push_back(root->val);
                    root = root->right;
                }
                else {
                    pred->left = NULL;
                    //res.push_back(root->val);
                    root = root->left;    
                }
            }
        }
        reverse(res.begin(),res.end());
        return;
    }
    void ite_solve3(TreeNode*  root, vector<int> &res){
        //O(n) -time and space
        stack<pair<TreeNode*,bool>> st;
        if(!root) return;
        st.push({root,false});
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            if(!p.first) continue;
            if(p.second) res.push_back(p.first->val);
            else{
                st.push({p.first,true});
                st.push({p.first->right,false});
                st.push({p.first->left,false});
            }
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        //ite_solve2(root,res);
        //morris_traversal(root,res);
        ite_solve3(root,res);
        return res;
        
    }
};