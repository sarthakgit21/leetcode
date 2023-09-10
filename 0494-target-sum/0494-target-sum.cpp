class Solution {
public:
    int tar;
    int t[2003][21];
    unordered_map<string,int> mp;
    int Countways(vector<int>& nums, int target,int ind){
        if(ind==nums.size()) {
            if(tar==target){
                return 1;
            }
            return 0;
        }
        string val=to_string(ind)+'#'+to_string(target);
        if(mp.find(val)!=mp.end()) return mp[val];
        
        int val1=target+nums[ind];
        int val2=target-nums[ind];
        
        int ans=0;
        ans+=Countways(nums,val1,ind+1);
        ans+=Countways(nums,val2,ind+1);
        return mp[val]=ans;
        
        
        
    } 
    
    int findTargetSumWays(vector<int>& nums, int val) {
        tar=val;
        memset(t,-1,sizeof(t));
        return Countways(nums,0,0);
    }
};