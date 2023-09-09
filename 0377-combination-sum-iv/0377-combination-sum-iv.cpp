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
    
    int combinationSum4(vector<int>& nums, int target) {
        int ans=0;
        memset(t,-1,sizeof t);
        ans=fun(nums,target,0);
        return ans;
    }
};