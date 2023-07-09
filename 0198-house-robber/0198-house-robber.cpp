class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int prev=nums[0];
    
        int cur=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int val=max(cur,prev+nums[i]);
            prev=cur;
            cur=val;
        }
        return cur;
    }
};