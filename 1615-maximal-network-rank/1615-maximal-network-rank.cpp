class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,set<int>> mp;
        
        
        for(auto x:roads)
        {
            int a=x[0];
            
            int b=x[1];
            
            mp[a].insert(b);
            mp[b].insert(a);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int val=mp[i].size()+mp[j].size();
                if(mp[i].find(j)!=mp[i].end()) val--;
                ans=max(ans,val);
            }
        }
        
        return ans;
    }
};