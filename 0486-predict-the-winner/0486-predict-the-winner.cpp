class Solution {
public:
    
    int dp[21][21];
    
    int fun(vector<int> nums,int n,int ind){
        if(ind>n) return 0;
        if(ind==n) return nums[n];
        
        if(dp[n][ind]!=-1)
            return dp[n][ind];
        
        int val=0;
        
        int take=nums[ind]-fun(nums,n,ind+1);
        int notTake=nums[n]-fun(nums,n-1,ind);
        
        return dp[n][ind]=max(take,notTake);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(nums,n-1,0)>=0;
    }
};