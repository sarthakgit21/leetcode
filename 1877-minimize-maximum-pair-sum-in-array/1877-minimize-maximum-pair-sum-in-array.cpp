class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=-1e9;
        
        sort(begin(nums),end(nums));
        
        int n=nums.size();
        
        for(int i=0;i<(n/2);i++){
            ans=max(ans,(nums[i]+nums[n-1-i]));
        }
        
        return ans;
    }
};