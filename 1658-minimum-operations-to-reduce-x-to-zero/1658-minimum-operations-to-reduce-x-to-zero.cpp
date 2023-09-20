class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        // vector<int> vals(nums);
        int sum=0;
        int ans=INT_MIN;
        
        map<int,int> mp;
        for(auto xx:nums) sum+=xx;
        cout<<sum;
        if(sum < x)
            return -1;
        int target=sum-x;
        mp[0]=-1;
        int val=0;
        for(int i=0;i<n;i++){
            val+=nums[i];
            mp[val]=i;
            if(mp.find(val-target)!=mp.end()){
                // cout<<val;
                ans=max(ans,i-mp[val-target]);
            }
        }
        
        return (ans==INT_MIN)?-1:(n-ans);
    }
};