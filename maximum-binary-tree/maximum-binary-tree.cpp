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
    //Naive is clearly O(n^2).
    //building sparse table :- O(nlogn) for preprocessing and O(1) per RMQ query.
    int n;
    int k;
    vector<vector<int>> dp;
    unordered_map<int,int> index;
    void init(vector<int>&nums){
        n = nums.size();
        k = log2(n)+5;
        dp.clear();
        dp.resize(n,vector<int>(k+1,0));
        for(int i =0;i<n;i++){
            dp[i][0] = nums[i];
        }
        for(int j=1;j<=k;j++){
            for(int i =0; i+ (1<<j) <=n;i++){
                dp[i][j] = max(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
            }
        }
        
    }
    int get_max(int s, int e){
        int l = log2(e-s+1);
        return max(dp[s][l],dp[e - (1<<l) +1][l]);
    }
    TreeNode* build_tree(int s, int e){
        if(s>e) return NULL;
        int val = get_max(s,e);
        //cout <<val<< " ";
        int idx = index[val];
        auto root = new TreeNode(val);
        root->left = build_tree(s,idx-1);
        root->right = build_tree(idx+1,e);
        return root;
    }
    TreeNode * solve1(vector<int> &nums){
        init(nums);
        index.clear();
        for(int i =0;i<n;i++){
            index[nums[i]] = i;
        }
        return build_tree(0,n-1);
    }
    TreeNode * solve2(vector<int> &nums){
        stack<TreeNode*> st;
        int n = nums.size();
        TreeNode * root = nullptr;
        for(int i= 0;i<n;i++){
            TreeNode * last = nullptr;
            while(!st.empty() && st.top()->val<=nums[i]){
                last = st.top();
                st.pop();
            }
            auto node = new TreeNode(nums[i]);
            if(!st.empty()){
                st.top()->right = node;
            }
            if(last){
                node->left = last;
            }
            st.push(node);
        }
        while(st.size()!=1){
            st.pop();
        }
        return root = st.top();
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //return solve1(nums);
        return solve2(nums);
    }
};