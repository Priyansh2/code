class Solution {
public:
    bool toposort(vector<vector<int>> &adj,vector<int> &order, int node, vector<int> &vis){
        vis[node] = 1;
        for(auto c : adj[node]){
            if(vis[c]==0 && toposort(adj,order,c,vis))return true;
            else if(vis[c]==1){
                return true;
            }
        }
        vis[node] = 2;
        order.push_back(node);
        return false;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int,vector<int>> mp;
        int c = m;
        for(int i =0;i<n;i++){
            if(group[i]==-1){
                group[i] = c++;
            }
            mp[group[i]].push_back(i);
        }
        vector<vector<int>> adj(n);
        vector<vector<int>> gadj(c);
        int k = beforeItems.size();
        for(int i =0;i<k;i++){
            for(auto x : beforeItems[i]){
                if(group[x]!=group[i]){
                    gadj[group[x]].push_back(group[i]);
                }
                else{
                    adj[x].push_back(i);
                }
            }
        }
        vector<int> vis(c,0);
        vector<int> gorder;
        for(int i= 0;i<c;i++){
            if(vis[i]!=0) continue;
            if(toposort(gadj,gorder,i,vis)) return {};
        }
        reverse(gorder.begin(),gorder.end());
        vector<int> res;
        for(auto gid : gorder){
            vis = vector<int> (n,0);
            vector<int> order;
            for(auto i : mp[gid]){
                //cout << i << " ";
                if(vis[i]!=0) continue;
                if(toposort(adj,order,i,vis)) return {};
            }
            reverse(order.begin(),order.end());
            res.insert(res.end(),order.begin(),order.end());
        }
        return res;
        
        
    }
};