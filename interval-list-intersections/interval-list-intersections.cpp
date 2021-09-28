class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int m = firstList.size(), n = secondList.size();
        int i =0,j=0;
        while(i<m && j<n){
            int left = max(firstList[i][0],secondList[j][0]);
            int right = min(firstList[i][1],secondList[j][1]);
            bool fl = true;
            if(right < left) fl = false;
            vector<int> p;
            if(fl) {
                p = {left,right};
                res.push_back(p);
            }
            if(left == firstList[i][0] && right == firstList[i][1]) i++;
            else if (left == firstList[i][0] && right == secondList[j][1]) j++; 
            else if (left == secondList[j][0] && right == firstList[i][1]) i++;
            else j++;
        }
        return res;
    }
};