class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k;
        int j=k;
        int ans=nums[k];
        int tar=nums[k];
        while(i>0||j<n-1){
            int left=(i>0) ? nums[i-1]:0;
            int right=  (j<n-1) ? nums[j+1]:0;
            if( left<right){
                j++;
                tar=min(tar,nums[j]);
            }
            else{
                i--;
                tar=min(tar,nums[i]);
            }
            // cout<<i<<" "<<j<<endl;
            ans=max(ans,tar*(j-i+1));
        }
        return ans;
    }
};