class dsu{
  public:
    vector<int> parent;
    vector<int> sz;
    dsu(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        sz.resize(n,1);
        
    }
    void init(int i ){
        parent[i] = i;
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
    int m, n;
    int get_index(int i, int j){
        return i*n+j;
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<int> rmax(m),cmax(n);
        dsu d(m*n);
        vector<vector<int>> rank(m,vector<int>(n));
        unordered_map<int,int> row_ele, col_ele;
        for(int i =0;i<m;i++){
            row_ele.clear();
            for(int j =0;j<n;j++){
                int id = get_index(i,j);
                if(row_ele.count(matrix[i][j])==0){
                    row_ele[matrix[i][j]] = id;
                }
                else{
                    d.merge(row_ele[matrix[i][j]],id);
                }
            }
        }
        for(int i =0;i<n;i++){
            col_ele.clear();
            for(int j =0;j<m;j++){
                int id = get_index(j,i);
                if(col_ele.count(matrix[j][i])==0){
                    col_ele[matrix[j][i]] = id;
                }
                else{
                    d.merge(col_ele[matrix[j][i]],id);
                }
            }
        }
        map<pair<int,int>,vector<int>> components;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int id = get_index(i,j);
                int par = d.find(id);
                components[{matrix[par/n][par%n],par}].push_back(id);
            }
        }
        //cout <<"ok!";
        
        for(auto &[leader, members] : components){
            //cout <<leader.first << " " << leader.second<< " " << members.size()<<endl;;
            int max_rank = 0;
            for(auto ids : members){
                int x= ids/n,y = ids%n;
                max_rank = max(max_rank, rmax[x]);
                max_rank = max(max_rank,cmax[y]);
            }
            max_rank++;
            for(auto ids: members){
                int x = ids/n, y= ids%n;
                rank[x][y] = max_rank;
                rmax[x] = max(rmax[x],max_rank);
                cmax[y] = max(cmax[y],max_rank);
            }
            
        }
        return rank;
        
    }
};