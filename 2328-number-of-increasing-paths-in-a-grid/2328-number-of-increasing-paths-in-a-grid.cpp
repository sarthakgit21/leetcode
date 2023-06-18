class Solution {
public:
    int mod=1e9+7;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(int x,int y,vector<vector<int>>& grid){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) return false;
        return true;
    }
    int dfs(vector<vector<int>> &dp,vector<vector<int>>& grid,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int val=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(isValid(nx,ny,grid)&&grid[i][j]<grid[nx][ny]){
                val=(val%mod+dfs(dp,grid,nx,ny)%mod)%mod;
            }
        }
        return dp[i][j]=val%mod;
    }
    
    
    int countPaths(vector<vector<int>>& grid) {

        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        long long ans=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=(ans%mod+dfs(dp,grid,i,j)%mod)%mod  ;
            }
        }
        return (int)ans%mod-1  ;
    }
};