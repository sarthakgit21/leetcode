class Solution {
public:
    int t[1001];
    int fun(vector<int>& nums, int target,int i){
        if(target==0)  return 1;
        if(t[target]!=-1) return t[target];
        int ans=0;
        
        for(int ind=i;ind<nums.size();ind++){
            if(nums[ind]<=target)
            ans+=fun(nums,target-nums[ind],i);
        }
        return t[target]=ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int val) {
        int ans=0;
        memset(t,-1,sizeof t);
        ans=fun(nums,val,0);
        return ans;
       
    }
};