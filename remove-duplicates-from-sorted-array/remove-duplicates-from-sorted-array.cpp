class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =0;
        int n = nums.size();
        if(n<=1) return n;
        for(int i =1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            nums[k++]  =nums[i-1];
        }
        if(k>0 && nums[k-1]!=nums[n-1]){
            nums[k++] = nums[n-1];
        }
        if(k ==0) nums[k++] = nums[0];
        return k;
    }
};