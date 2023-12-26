class Solution {
public:
    int dp[3000][50];
    const int mod=1e9+7;
    int fun(int n, int k, int target, int ind){
        if(target==0 && n==0) return 1;
        if(target<0 || n<0) return 0;
        if(dp[target][n]!=-1) return dp[target][n];
        int ans=0;
        for(int i=1;i<=k;i++){
            if(target>=i)
                ans+=(fun(n-1,k,target-i,ind));
            ans%=mod;
        }
        return dp[target][n]=ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return fun(n,k,target,1);
    }
};