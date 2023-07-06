class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int i=0;
        long sum=0;
        int ans=INT_MAX;
        while(j<n){
            sum+=nums[j];
            if(sum<target){
                j++;
            }
            else{
                // cout<<sum<<endl;
                while(sum>=target && i<n){
                    ans=min(ans,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};