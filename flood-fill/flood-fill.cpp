class Solution {
public:
    bool valid(int a, int b, vector<vector<int>>&image){
        int m= image.size(), n = image[0].size();
        return a<m && b<n && a>=0 && b>=0;
        
    }
    void dfs(int a, int b, vector<vector<int>> &image, int oc, int nc){
        if(!valid(a,b,image)) return;
        if(image[a][b]!=oc) return;
        image[a][b] = nc;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(auto d : dir){
            int x = a + d.first, y = b + d.second;
            dfs(x,y,image,oc,nc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old_color = image[sr][sc];
        if(newColor == old_color) return image;
        dfs(sr,sc,image,old_color,newColor);
        return image;
    }
};