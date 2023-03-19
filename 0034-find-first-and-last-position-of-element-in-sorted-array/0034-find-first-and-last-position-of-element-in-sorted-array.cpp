class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=-1;
        int high=-1;
        int val=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int val2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int n=nums.size();
        if(n==0||val==n) return {-1,-1};
        if(nums[val]!=target) return {low,high};
        return {val,val2-1};
        
    }
};