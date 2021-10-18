class Solution {
public:
    int partition(vector<int>&nums, int l, int r){
        int pivot = nums[r];
        int j =l;
        for(int i =l;i<r;i++){
            if(pivot <=nums[i]) swap(nums[i],nums[j++]);
        }
        assert(j <= r);
        swap(nums[j],nums[r]);
        return j;
    }
    int solve(vector<int>&nums, int k, int l, int r){
        if(l>r) return INT_MAX;
        int p = partition(nums,l,r);
        if(k-1 == p) return nums[p];
        return k-1 < p ? solve(nums,k,l,p-1) : solve(nums,k,p+1,r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums,k,0,nums.size()-1);
    }
};