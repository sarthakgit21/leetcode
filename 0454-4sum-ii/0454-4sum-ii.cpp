class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d)    {
        unordered_map<int,int> mp;
        for(auto z:c){
            for(auto w:d)
            {
                mp[w+z]++;
            }
        }
        int ans=0;
        for(auto x:a){
            for(auto y:b){
                    if(mp.find(-1*(x+y))!=mp.end()) ans+=mp[-(x+y)];
                }
        }
        return ans;
    }
};