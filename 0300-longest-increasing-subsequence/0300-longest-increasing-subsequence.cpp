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
        vector<int> ans;
        int l=1;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(ans.back()<nums[i]) {
                ans.push_back(nums[i]);
                l++;
            }
            else{
                int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ind]=nums[i];
            }
        }
        return l;
    }
};