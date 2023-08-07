class Solution {
public:
    
    
    bool isValid(vector<vector<int>>& dp,int mid,int i,int j,vector<vector<int>> &dp2)
    {
        int n=dp.size();
        int m=dp[0].size();
        if(i==n-1&&j==m-1) return true;
        dp2[i][j]=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        
        // cout<<i<<j<<mid<<dp[i][j]<<endl;
        
        for(int k=0;k<4;k++)
        {
            int nextX=i+dx[k];
            int nextY=j+dy[k];
            
            if(nextX<0||nextY<0||nextX>=n||nextY>=m||dp[nextX][nextY]<mid||dp2[nextX][nextY])
                continue;
                
            if(isValid(dp,mid,nextX,nextY,dp2)) return true;    
            
        }
        // dp2[i][j]=0;

        
        return false;
        
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        
        int dis=0;
        while(!q.empty())
        {
            int sz=q.size();
            dis++;
            while(sz--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(int i=0;i<4;i++)
                {
                    int nextX=x+dx[i];
                    int nextY=y+dy[i];
                    
                    if(nextX<0||nextY<0||nextX>=n||nextY>=m||dp[nextX][nextY]!=-1) continue;
                    
                    dp[nextX][nextY]=dis;
                    q.push({nextX,nextY});
                    
                }
                
            }
        }
        
        int low=0;
        int high=dis-1;
        
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // cout<<mid<<endl;
            vector<vector<int>> dp2(n,vector<int> (m,0));
            if(dp[0][0]>=mid&&isValid(dp,mid,0,0,dp2)){          
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
        
    }
};