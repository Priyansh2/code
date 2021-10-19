class Solution {
public:
    int solve1(vector<int>&nums){
        int n = nums.size();
        for(int i =0;i<n;i++){
            int j = nums[i];
            if(nums[abs(j)-1]>=0) nums[abs(j)-1]= -nums[abs(j)-1];
            else return abs(j);
        }
        return -1;
    }
    int solve2(vector<int> &nums){
        return 0;
    }
    int findDuplicate(vector<int>& nums) {
        return solve1(nums);
    }
};