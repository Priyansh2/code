class Solution {
public:
    static bool compare(string &s1, string &s2){
        int l1 = s1.length(), l2= s2.length();
        if(l1!=l2) return l1>l2;
        return s1 > s2;
    }
    string solve1(vector<string>&nums, int k){
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }
    int partition(vector<string> &nums, int l, int r){
        int n = rand()%(r-l+1);
        swap(nums[l+n],nums[r]);
        string pivot = nums[r];
        int i=l;
        n = nums.size();
        for(int j =l;j<r;j++){
            if(compare(nums[j],pivot)){
                swap(nums[i++],nums[j]);
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
    string solve(vector<string> &nums, int l, int r, int k){
        /*if(l>r) return "";
        int p = partition(nums,l,r);
        if(p==k-1)return nums[p];
        return k-1 < p ? solve(nums,l,p-1,k) : solve(nums,p+1,r,k);*/
        
        /*while(l<=r){
            int p =partition(nums,l,r);
            if(p==k-1) return nums[p];
            else if(k-1 < p) r = p-1;
            else l = p+1;
        }
        return "";*/
        nth_element(nums.begin(),nums.begin() + k-1 , nums.end(),compare);
        return nums[k-1];
    }
    string solve2(vector<string>&nums, int k){
        srand(time(0));
        
        return solve(nums,0,nums.size()-1,k);
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        //return solve1(nums,k);
        return solve2(nums,k);
    }
};