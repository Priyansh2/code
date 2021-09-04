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
    int sumEvenGrandparent(TreeNode* root) {
        queue <tuple<TreeNode*,bool,bool>> q;
        q.push({root,false,false});
        int sum =0;
        while(!q.empty()){
            int l = q.size();
            while(l--){
                auto p = q.front();
                q.pop();
                auto node = get<0>(p);
                auto par_even = get<1>(p);
                auto gpar_even= get<2>(p);
                bool t = node->val &1 ? false : true;
                if(node->left){
                    q.push({node->left,t,par_even});
                }
                if(node->right){
                    q.push({node->right,t,par_even});
                }
                if(gpar_even) sum+=node->val;
            }
        }
        return sum;
    }
};