class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int num=k%nums.size();
        int n=nums.size();
        vector<int> val;
        for(int i=n-num;i<n;i++)
        {
            val.push_back(nums[i]);
        }
        
        for(int i=0;i<n-num;i++)
        {
            val.push_back(nums[i]);
        }
        
        nums=val;
        
        
    }
};