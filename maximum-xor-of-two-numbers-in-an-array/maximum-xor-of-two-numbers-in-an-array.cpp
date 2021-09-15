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
    int findMaximumXOR(vector<int>& nums) {
        return solve1(nums);
        //return solve2(nums);
    }
};