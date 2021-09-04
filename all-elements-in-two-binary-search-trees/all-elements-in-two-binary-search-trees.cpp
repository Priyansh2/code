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
    void inorder(node * root,vector<int> &arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> solve1(node* root1, node *root2){
        vector<int> arr1;
        vector<int> arr2;
        inorder(root1,arr1);
        inorder(root2,arr2);
        int m = arr1.size(), n = arr2.size();
        vector<int> res(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(arr1[i] <= arr2[j]){
                res[k] = arr1[i];
                i++;
            }
            else {
                res[k] = arr2[j];
                j++;
            }
            k++;
        }
        while(i<m){
            res[k++] = arr1[i++];
        }
        while(j<n){
            res[k++] = arr2[j++];
        }
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        return solve1(root1,root2);    
    }
};