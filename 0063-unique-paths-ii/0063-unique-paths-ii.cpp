class Solution {
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i,j;
        int n=obstacleGrid[0].size();
        int m=obstacleGrid.size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0&&j==0) dp[i][j]=1;
                // else 
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};