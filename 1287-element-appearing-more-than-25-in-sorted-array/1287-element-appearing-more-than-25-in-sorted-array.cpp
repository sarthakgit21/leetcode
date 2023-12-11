class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto x:arr) mp[x]++;
        for(auto [x,y]:mp) if(y>(n/4)) return x;
        return -1;
        
    }
};