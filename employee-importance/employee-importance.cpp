/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,int> mp;
    int dfs(int node_id, vector<Employee*> &adj){
        int sum = 0;
        for(auto x : adj[mp[node_id]]->subordinates){
            sum+=dfs(x,adj);
        }
        sum+=adj[mp[node_id]]->importance;
        return sum;
    }    
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size(); 
        for(int i =0;i<n;i++){
            mp[employees[i]->id] = i;
        }
        return dfs(id,employees);
    }
};