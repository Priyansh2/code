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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mine=INT_MAX, maxe = INT_MIN;
        while(!q.empty()){
            auto l = q.size();
            unordered_map<int,vector<int>> temp;
            while(l--){
                auto p = q.front();
                q.pop();
                auto node = p.first;
                auto d= p.second;
                mine = min(mine,d);
                maxe = max(maxe,d);
                if(node->left) q.push({node->left,d-1});
                if(node->right) q.push({node->right,d+1});
                temp[d].push_back(node->val);
            }
            for(auto it = temp.begin();it!=temp.end();it++){
               sort(temp[it->first].begin(),temp[it->first].end());
               mp[it->first].insert(mp[it->first].end(),temp[it->first].begin(),temp[it->first].end()); 
            }
            
        }
        for(int i= mine;i<=maxe;i++){
            if(mp.find(i)!=mp.end()){
                res.push_back(mp[i]);
            }
        }
        return res;
        
    }
};