class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int mini=newInterval[0];
        int maxi=newInterval[1];
        int i=0;
        int n=nums.size();
        int m=newInterval.size();
        
        if(n==0) return {newInterval};
        if(nums[0][0]>maxi) ans.push_back({mini,maxi});
        for(;i<nums.size();i++){
            if((nums[i][1]>=mini&&nums[i][0]<=mini)||(mini<=nums[i][0]&&nums[i][0]<=maxi))
            {
                int val1=min(mini,nums[i][0]);
                int val2=0;
                while(i+1<n&&(nums[i+1][0]<=maxi)) i++;
                val2=max(maxi,nums[i][1]);
                
                ans.push_back({val1,val2});
            }
            else
            {
                ans.push_back(nums[i]);
                if(i+1<n&&nums[i+1][0]>maxi&&nums[i][1]<mini) ans.push_back(newInterval);
            }
        }
        
        if(ans.back()[1]<mini) ans.push_back({mini,maxi});
        return ans;
        
    }
};