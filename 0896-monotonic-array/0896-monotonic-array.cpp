class Solution {
public:
    bool isSroted(vector<int> nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        vector<int> vals(nums);
        reverse(vals.begin(),vals.end());
        return isSroted(vals)|| isSroted(nums);
    }
};