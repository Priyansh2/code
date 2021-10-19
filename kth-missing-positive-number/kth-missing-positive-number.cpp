class Solution {
public:
    int solve1(vector<int>&arr, int k){
        unordered_set<int> st(arr.begin(),arr.end());
        int n = arr.size();
        int cnt=k;
        for(int i =1;i<=n + k;i++){
            if(st.count(i)==0) {
                cnt--;
            }
            if(cnt ==0) return i;
        }
        return 0;
    }
    int findKthPositive(vector<int>& arr, int k) {
        return solve1(arr,k);
    }
};