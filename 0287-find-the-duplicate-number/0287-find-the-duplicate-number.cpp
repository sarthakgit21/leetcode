class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int j=nums.size();
        int i=0;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(i=0;i<j-1;i++){
            if(nums[i]==nums[i+1]) ans=nums[i];
        }
        return ans;
    }
};