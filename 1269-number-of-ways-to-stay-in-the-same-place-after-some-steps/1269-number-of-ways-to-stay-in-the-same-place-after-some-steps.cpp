class Solution {
public:
    int dp[501][501];
    const int mod=1e9+7;
    int fun(int ind,int steps,int n){
        if(ind<0|| ind>=n) return 0;
        if(steps==0){
            if(ind==0) return 1;
            return 0;
        }
        if(dp[ind][steps]!=-1) return dp[ind][steps];
        int val=fun(ind,steps-1,n);
        val%=mod;
        val+=fun(ind+1,steps-1,n);
        val%=mod;
        val+=fun(ind-1,steps-1,n);
        val%=mod;
        return dp[ind][steps]=val;
        
    }
    
    int numWays(int steps, int arrLen) {
        int n=min(steps,arrLen);
        memset(dp,-1,sizeof dp);
        return fun(0,steps,n);
    }
};