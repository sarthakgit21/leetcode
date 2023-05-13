const int mod=1e9+7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long> dp(high+zero+one+1,0);
        for(int i=high;i>=0;i--)
        {
            long ans=(dp[i+zero]%mod+dp[i+one]%mod)%mod;
            if(i>=low&&i<=high)
            {
                ans=(ans+1)%mod;
            }
            dp[i]=ans;
        }
        return (int)dp[0];
    }
};