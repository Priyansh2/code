class Solution {
public:
    int solve1(vector<int>&nums){
        int n = nums.size();
        for(int i =0;i<n;i++){
            int j = abs(nums[i]);
            if(nums[j-1]>=0) nums[j-1]*=-1;
            else return j;
        }
        return -1;
    }
    int solve2(vector<int> &nums){
        int n = nums.size();
        for(auto &x : nums) x--;
        for(auto &x : nums){
            nums[x%n]+=n;
            //if(nums[x%n] >= 2*n) return x%n+1; --this will save from using below extra loop;
        }
        for(int i =0;i<n;i++){
            if(nums[i]/n > 1) return i+1;
        }
        return -1;
        
    }
    int solve3(vector<int>&nums, int i=0){
        int temp = nums[i];
        if(nums[i] ==i) return i;
        nums[i] = i;
        return solve3(nums,i=temp);
    }
    int findDuplicate(vector<int>& nums) {
        //return solve1(nums);
        //return solve2(nums);
        return solve3(nums);
    }
};