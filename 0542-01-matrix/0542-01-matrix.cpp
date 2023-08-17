class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i,j}),vis[i][j]=1;
            }
        }
    
        int steps=0;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nx=dx[i]+x;
                    int ny=dy[i]+y;
                    if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny]==1) continue;
                    q.push({nx,ny});
                    // cout<<nx<<" "<<ny<<endl;
                    vis[nx][ny]=1;
                mat[nx][ny]=steps+1;
                
                }

            }
                                        steps++;

        }
        return mat;
    }
};