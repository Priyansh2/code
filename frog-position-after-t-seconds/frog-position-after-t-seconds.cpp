class Solution {
public:
    vector<vector<int>> g;
    double ans;
    void dfs(int root, int parent, int curr_time, int target, int t, double prob){
        if(ans!=0) return;
        //cout <<prob<< " "<<endl;
            
        if(root==target){
            if(curr_time ==t) {
                ans = prob;
                //cout <<"lol1"<<endl;
            }
            else if ((g[root].size()==0 || g[root].size()==1 && parent!=0) && curr_time<=t){
              ans = prob;
               //cout <<"lol"<<endl; 
            } 
        }
        int b = g[root].size();
        if (parent!=0) b--;        
        for(auto ch : g[root]){
            if(ch!=parent){
                auto a =(double)1/b;
                dfs(ch,root,curr_time +1, target, t, prob*a);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        g.resize(n+1);
        ans =0;
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(1,0,0,target,t,1);
        return ans;
    }
};