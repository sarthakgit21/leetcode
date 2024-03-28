class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        
        int n=nums.size();
        int ans=-1;
        
        int i=0;
        int j=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                ans=max(ans,j-i);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};