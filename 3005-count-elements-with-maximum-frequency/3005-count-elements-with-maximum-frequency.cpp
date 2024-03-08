class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(auto c:nums){
            mp[c]++;
        }
        int maxi=0;
        for(auto x:mp) maxi=max(maxi,x.second);
        int ans=0;
        for(auto x:mp) if(x.second==maxi) ans+=maxi;
        return ans;

    }
};