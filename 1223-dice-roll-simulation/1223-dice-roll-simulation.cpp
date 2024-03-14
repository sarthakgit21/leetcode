class Solution
{
    public:
    int dp[5005][20][10];
        const int mod = 1e9 + 7;
    int fun(int n, vector<int> &nums, int ind, int x, int num, string ss)
    {
        if(num>=7) return 0;
        if (ind == n)
        {
            return 1;
        }
        if(dp[ind][x][num]!=-1) return dp[ind][x][num];
        int ans = 0;;

        for (int i = 1; i <= 6; i++)
        {
            if(num==i && x<nums[i-1]){
                ans+=fun(n,nums,ind+1,x+1,i,ss);
                ans%=mod;
            }
            if(num!=i){
                ans+=fun(n,nums,ind+1,1,i,ss);
                ans%=mod;
            }
        }
        ans%=mod;
        return dp[ind][x][num]=ans;
    }

    int dieSimulator(int n, vector<int> &rollMax)
    {
        memset(dp,-1,sizeof dp);
        return fun(n, rollMax, 0, 0, 1, "");
    }
};