class Solution {
public:
    int fun(vector<int> & nums,int n,int ind,int prev,vector<vector<int>> &dp){
        if(ind<0) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int l=fun(nums,n,ind-1,prev,dp);
        if(prev==-1||nums[ind]<nums[prev]){
            l=max(l,1+fun(nums,n,ind-1,ind,dp));
        }
        return dp[ind][prev+1]=l;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(nums,n,n-1,-1,dp);
    }
};