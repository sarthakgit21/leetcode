class Solution {
public:
    int t[201][1001];
    int fun(vector<int>& nums, int target,int i){
        if(i>=nums.size()) return 0;
        if(target==0)  return 1;
        if(t[i][target]!=-1) return t[i][target];
        int ans=0;
        
        for(int ind=i;ind<nums.size();ind++){
            if(nums[ind]<=target)
            ans+=fun(nums,target-nums[ind],i);
        }
        return t[i][target]=ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int val) {
        int ans=0;
        memset(t,0,sizeof t);
        // ans=fun(nums,target,0);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(val+1,0));
        
        for(int i=n;i>=0;i--){
            
            for(int target=0;target<=val;target++){
                
                if(i>=nums.size()) { dp[i][target]=0;continue;}
                if(target==0)  {dp[i][target]=1;continue;}
                long ans=0;

                for(int ind=i;ind<nums.size();ind++){
                    if(nums[ind]<=target)
                    ans+=dp[i][target-nums[ind]];
                }
                dp[i][target]=ans;
                
            }
            
        }
        
        return dp[0][val];
    }
};