class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto temp = heights;
        sort(temp.begin(),temp.end());
        int cnt=0;
        for(int i =0;i<temp.size();i++) if(heights[i]!=temp[i]) cnt++;
        return cnt;
    }
};