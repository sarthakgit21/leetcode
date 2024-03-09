class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(auto x:nums2) mp[x]++;
        
        for(auto x:nums1) if(mp.count(x)) return x;
        
        
        
        return -1;
    }
};