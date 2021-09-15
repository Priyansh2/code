class node{
    public:
    
    node *left;
    node * right;
    int val;
    node(int val= -1){
        left = nullptr;
        right = nullptr;
        this->val = val;
    }
};
class Solution {
public:
    int solve1(vector<int> &nums){
        int n = nums.size();
        int maxxor = 0;
        int mask = 0;
        unordered_set<int> st;
        for(int i = 30;i>=0;i--){
            mask  = mask | (1 << i);
            st.clear();
            for(int j = 0;j<n;j++){
                st.insert(nums[j] & mask);
            }
            auto temp = maxxor | (1 << i);
            for(auto & x : st){
                if(st.find(x^temp)!=st.end()){
                    maxxor = temp;
                    break;
                }
            }
            
        }
        return maxxor;
        
    }
    void insert(int n, int k, node *root){
        if(k<0) return;
        int bit = (n >> k) & 1;
        if(bit==0){
            if(!root->left) root->left = new node(bit);
            root = root->left;
        }
        else{
            if(!root->right) root->right = new node(bit);
            root =root->right;
        }
        insert(n,k-1,root);
    }
    
    int solve2(vector<int> &nums){
        node * root=  new node();
        for(auto x : nums){
            insert(x,30,root);
        }
        int res = 0;
        for(auto x : nums){
            int maxxor = 0;
            auto t = root;
            for(int i = 30;i>=0;i--){
                int bit =(x >> i) & 1;
                if(bit==0){
                    if(t->right){
                        t =t->right;
                        maxxor+= 1 << i;
                    }
                    else t = t->left;
                }
                else{
                    if(t->left){
                        t = t->left;
                        maxxor+= 1 << i;
                    }
                    else t =t->right;
                }
            }
            res = max(res,maxxor);
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        //return solve1(nums);
        return solve2(nums);
    }
};