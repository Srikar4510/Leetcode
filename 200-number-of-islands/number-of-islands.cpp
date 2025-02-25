class Solution {
public:
    void dfs(int x,int y,int m,int n,vector<vector<char>>& grid){
       if(x<0 or x==m or y<0 or y==n or grid[x][y]=='0'){
         return;
       }
        grid[x][y]='0';

        dfs(x-1,y,m,n,grid);
        dfs(x+1,y,m,n,grid);
        dfs(x,y-1,m,n,grid);
        dfs(x,y+1,m,n,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                  ans++;
                  dfs(i,j,m,n,grid);
                }
            }
        }
        return ans;
    }
};