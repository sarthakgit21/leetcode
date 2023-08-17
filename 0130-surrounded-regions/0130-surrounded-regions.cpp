class Solution {
public:
    
    
    void dfs(vector<vector<int>> &vis,vector<vector<char>>& board,int i,int j,int n,int m)
    {
        vis[i][j]=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        
        for(int k=0;k<4;k++)
        {
           int new_i=i+dx[k];
           int new_j=j+dy[k];
            // cout<<i<<" "<<j<<endl;
            if(new_i<0||new_i>=n||new_j<0||new_j>=m||vis[new_i][new_j]||board[new_i][new_j]=='X')
                continue;
            dfs(vis,board,new_i,new_j,n,m);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0]&&board[i][0]=='O')
            {
                dfs(vis,board,i,0,n,m);
            }
            
            if(!vis[i][m-1]&&board[i][m-1]=='O')
            {
                dfs(vis,board,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i]&&board[0][i]=='O')
            {
                // cout<<i<<" "<<0<<endl;
                dfs(vis,board,0,i,n,m);
            }
            
            if(!vis[n-1][i]&&board[n-1][i]=='O')
            {
                dfs(vis,board,n-1,i,n,m);
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};