class Solution {
public:
    vector<int> solve1(vector<int> &nums, int k){
        vector<int> res;
        deque<pair<int,int>> dq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            while(!dq.empty() && dq.front().second <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back().first <= nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            if(i>=k-1) res.push_back(dq.front().first);
        }
        return res;
    }
    vector<int> solve2(vector<int> &nums, int k){
        stack<pair<int,int>> st;
        int n = nums.size();
        vector<int> nge(n);
        vector<int> res;
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && nums[i] > st.top().second){
                st.pop();
            }
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top().first;
            st.push({i,nums[i]});
        }
        int j =0;
        for(int i =0;i<=n-k;i++){
            if(j<i) j = i;
            int temp = nums[j];
            while(nge[j]< i + k){
                j = nge[j];
            }
            res.push_back(nums[j]);
        }
        return res;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //return solve1(nums,k);     
        return solve2(nums,k);
    }
};