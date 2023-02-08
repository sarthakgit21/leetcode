class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,10001);
        dp[n-1]=0;
        for(int indx=n-1;indx>=0;indx--)
        {
          for(int i=nums[indx];i>=1;i--)
          {
            if(indx+i<=n-1)dp[indx]=min(dp[indx],1+dp[indx+i]);
          }
            
        }
        
       return dp[0]; 
        
    }
};