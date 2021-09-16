class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,vector<int>> pos ={
            {0,{1,3}},
            {1,{0,2,4}},
            {2,{1,5}},
            {3,{0,4}},
            {4,{1,3,5}},
            {5,{2,4}}
            
        };
        //cout <<"sasa"<<endl;
        queue <pair<string,int>> q;
        unordered_set<string> vis;
        string s;
        int p;
        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0) p =i*3+j;  
                s+=to_string(board[i][j]);
            }
        }
        q.push({s,p});
        vis.insert(s);
        int lvl =0;
        while(!q.empty()){
            int l = q.size();
            while(l--){
                auto p = q.front();
                q.pop();
                s = p.first;
                if(s=="123450") return lvl;
                int idx = p.second;
                for(auto id : pos[idx]){
                    auto temp = s;    
                    swap(temp[idx],temp[id]);
                    if(vis.count(temp)) continue;
                    vis.insert(temp);
                    q.push({temp,id});
                }

            }
            lvl++;
        }
        return -1;
    }
};