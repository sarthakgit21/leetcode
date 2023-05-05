class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto x:nums) mp[x]++;
        for(auto x:mp){
            p.push({x.second,x.first});
            if(p.size()>k) p.pop();
        }
        // k--;
        vector<int> ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};