class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,pair<int,int>>mp;
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<2*nums.size();i++)
        {
            if(mp.find(nums[i%n])!=mp.end())
            {
                mp[nums[i%n]]={i,max(mp[nums[i%n]].second,((i-mp[nums[i%n]].first)/2))};
            }
            else{

                mp[nums[i%n]]={i,0};

            }

        }
        
        for(auto it:mp){
            ans=min(ans,(int)it.second.second);
        }
        
        return ans;
    }
};