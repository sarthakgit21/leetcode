class Solution {
public:
    
    bool solve(int ind,int know,vector<int>& nums, int k,int cursum,int req,vector<int>&vis){
        if(know==k+1){ return true;}
        if(cursum==req) {return solve(0,know+1,nums,k,0,req,vis);}
        if(cursum>req) return false;
        if(ind>=nums.size()) return false;
        for(int i = ind; i < nums.size(); i++){
            if(vis[i])
                continue;
            vis[i] = true;
            if(solve(i+1,know,nums,k,cursum+nums[i],req,vis))
                return true;
            vis[i] = false;
            if(cursum==0)break;
        }
        return false;
        
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        vector<int> vis(nums.size(),0);
        return solve(0,1,nums,k,0,sum/k,vis);
    }
};