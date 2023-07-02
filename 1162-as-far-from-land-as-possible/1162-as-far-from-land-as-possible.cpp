class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis=grid;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.empty()|| q.size()==m*n) return -1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                int x=it.first;
                int y=it.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(ny<0||nx<0||nx>=n||ny>=m||vis[nx][ny]==1) continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
            ans++;

        }
        return ans-1;
    }
};