class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> indegree(n,0);
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        for(auto x:roads)
        {
            int a=x[0];
            
            int b=x[1];
            
            indegree[a]++;
            indegree[b]++;
            
            
            vis[a][b]=1;
            vis[b][a]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int val=indegree[i]+indegree[j];
                if(vis[i][j]) val--;
                ans=max(ans,val);
            }
        }
        
        return ans;
    }
};