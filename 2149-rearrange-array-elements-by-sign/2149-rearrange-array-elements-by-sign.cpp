class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(nums[i]);
                ans.push_back(-1);
            }
        }
        int k=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                // ans.push_back(nums[i]);
                ans[k]=nums[i];
                k+=2;
            }
        }
        return ans;
    }
};