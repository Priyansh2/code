class Solution {
public:
    static inline int x;
    static bool compare(int &a, int &b){
        int t1 = abs(a-x), t2 = abs(b-x);
        return t1!=t2 ? t1 < t2 : a < b;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        this->x = x;
        priority_queue<int,vector<int>, decltype(&compare)> pq(compare);
        vector<int>res;
        for(auto &num : arr){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};