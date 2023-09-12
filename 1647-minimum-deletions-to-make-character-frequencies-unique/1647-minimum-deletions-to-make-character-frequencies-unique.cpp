class Solution {
public:
    int minDeletions(string s) {
        vector<int> vis(26,0);
        for(auto x:s) vis[x-'a']++;

        sort(vis.begin(),vis.end());
        int ans=0;
        for(int i=24;i>=0&&vis[i]>0;i--){
            
            if(vis[i]>=vis[i+1]){
                
                int val=vis[i];
                vis[i]=max(0,vis[i+1]-1);
                ans+=val-vis[i];
            }
            
        }
        return ans;
        
    }
};