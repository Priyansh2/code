class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> st(nums.begin(),nums.end());
        int maxlen = 0;
        while(!st.empty()){
            auto p = st.begin();
            int a = *p, b = *p;
            int len = 1;
            st.erase(p);
            while(st.find(a+1)!=st.end()){
                st.erase(st.find(a+1));
                a++;
                len++;
            }
            maxlen = max(maxlen, len);
            len = 1;
            while(st.find(b-1)!=st.end()){
                st.erase(st.find(b-1));
                b--;
                len++;
            }
            maxlen = max(maxlen , len);
        }
        return maxlen;
        
        
        
    }
};