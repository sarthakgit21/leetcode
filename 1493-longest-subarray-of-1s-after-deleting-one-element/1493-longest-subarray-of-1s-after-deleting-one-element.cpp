class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=0;
        int low=0;
        int high=0;
        int n=nums.size();
        int ans=0;
        while(high<n&&low<n){
            if(nums[high]==1){
                high++;
            }
            else{
                if(k==0){
                    high++;
                    k++;
                }
                else{
                    while(low<n && k>0){
                        if(nums[low]==0) k--;
                        low++;
                    }
                    
                }
            }
            ans=max(ans,high-low-k);
        }
        if(k==0) ans--;
        return ans;
    }
};