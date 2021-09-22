class dsu{
  public:
    vector<int> parent;
    vector<int> sz;
    dsu(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        sz.resize(n,1);
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }
    bool merge(int i, int j){
        i = find(i);
        j = find(j);
        if(i==j) return false;
        if(sz[i] < sz[j]) swap(i,j);
        parent[j] = i;
        sz[i]+=sz[j];
        return true;
    }
};
class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int>&v2){
        return v1[2] < v2[2];
    }
    string get_serial(vector<int> &edge){
        return to_string(edge[0]) + "," + to_string(edge[1]) + "," + to_string(edge[2]);
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        dsu uf(n);
        int m = edges.size();
        unordered_map<string,int> idx;
        for(int i =0;i<m;i++){
            idx[get_serial(edges[i])] = i;
        }
        sort(edges.begin(),edges.end(),cmp);
        int mincost = 0;
        for(auto & edge : edges){
            int u = edge[0], v = edge[1] , wt = edge[2];
            if(!uf.merge(u,v)) continue;
            mincost+=wt;
        }
        vector<bool> mark(m,false);
        unordered_set<int> crit,pcrit;
        for(auto &edge : edges){
            int id = idx[get_serial(edge)];
            mark[id] = true;
            int temp = 0;
            iota(uf.parent.begin(),uf.parent.end(),0);
            fill(uf.sz.begin(),uf.sz.end(),1);
            int cnt = 0;
            for(auto &edge :edges){
                int id2 = idx[get_serial(edge)];
                if(mark[id2]) continue;
                int u = edge[0], v = edge[1] , wt = edge[2];
                if(!uf.merge(u,v)) continue;
                temp+=wt;
                cnt++;
                if(cnt == n-1) break;
            }
            if(temp > mincost || cnt < n-1){
                crit.insert(id);
            }
            mark[id] =false;
        }
        for(auto &edge : edges){
            int id = idx[get_serial(edge)];
            if(crit.count(id)==1) continue;
            int u = edge[0], v = edge[1] , wt = edge[2];
            iota(uf.parent.begin(),uf.parent.end(),0);
            fill(uf.sz.begin(),uf.sz.end(),1);
            uf.merge(u,v);
            int temp=wt;
            int cnt = 0;
            for(auto &edge :edges){
                int id2 = idx[get_serial(edge)];
                u = edge[0], v = edge[1] , wt = edge[2];
                if(!uf.merge(u,v)) continue;
                temp+=wt;
                cnt++;
                if(cnt == n-1) break;
            }
            if(temp == mincost) pcrit.insert(id);
        }
        return {vector<int>(crit.begin(),crit.end()),vector<int>(pcrit.begin(),pcrit.end())};
    }
};