class Solution {
public:
    int tar;
    int t[2003][21];
    int Countways(vector<int>& nums, int target,int ind){
        if(ind==nums.size()) {
            if(tar==target){
                return 1;
            }
            return 0;
        }
        if(t[target+1000][ind]!=-1) return t[target+1000][ind];
        
        int val1=target+nums[ind];
        int val2=target-nums[ind];
        
        int ans=0;
        ans+=Countways(nums,val1,ind+1);
        ans+=Countways(nums,val2,ind+1);
        return t[target+1000][ind]=ans;
        
        
        
    } 
    
    int findTargetSumWays(vector<int>& nums, int val) {
        tar=val;
        memset(t,-1,sizeof(t));
        return Countways(nums,0,0);
    }
};