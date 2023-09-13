class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                ans[i]=1+ans[i-1];
            }
        }
        
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                
                if(ans[i]<=ans[i+1]){
                    ans[i]=1+ans[i+1];
                }
                
            }
        }
        // for(auto x:ans){cout<<x<<" ";}
        
        int val=0;
        for(int i=0;i<n;i++){
            val+=ans[i];
        }
        return val;
        
    }
};