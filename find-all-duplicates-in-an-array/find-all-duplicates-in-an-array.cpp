class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(auto &x :nums) x--;
        for(int i =0;i<n;i++){
            nums[nums[i]%n]+=n;
        }
        for(int i =0;i<n;i++){
            if(nums[i]/n == 2) res.push_back(i+1);
        }
        return res;
    }
};