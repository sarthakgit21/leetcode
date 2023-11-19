class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums) mp[x]++;
        auto it=mp.begin();
        int val=1;
        it++;
        int ans=0;
        for(;it!=mp.end();it++){
            ans+=(val*(it->second));
            val++;
        }
        return ans;;
    }
};