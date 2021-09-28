class Solution {
public:
    vector<vector<int>> adj;
    vector<int>color;
    vector<int> parent;
    bool dfs(int node,int par, vector<int> &nums){
        //cout <<node <<endl;
        color[node] = 1;
        parent[node] = par;
        bool fl = true;
        for(auto &c : adj[node]){
            //cout <<node << " "<<c<<endl;
            if(color[c]==1){
                int start = c,end = node;
                //cout <<start << " " <<end << endl;
                if(start==end){
                    color[node] = 2;
                    return false;  
                } 
                int sign = nums[start] >0 ? 1 : -1;
                while(end!=start){
                    if(sign*nums[end]  < 0) {
                        color[node] = 2;
                        return false;
                    }
                    end = parent[end];
                }
                return true;
            }
            if(color[c]==0 && dfs(c,node, nums)) return true;
        }
        color[node] = 2;
        return false;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        adj.resize(n);
        color.resize(n,0);
        parent.resize(n,-1);
        for(int i =0;i<n;i++){
            int j = ceil((double)abs(i+nums[i])/n);
            cout << i << " " <<j<<endl;
            adj[i].push_back((nums[i] + i + j*n)%n);
        }
        for(int i =0;i<n;i++){
            if(color[i]==0 && dfs(i,-1,nums))return true;
        }
        return false;
    }
};