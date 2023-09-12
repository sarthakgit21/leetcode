class Solution {
public:
    int minDeletions(string s) {
        vector<int> vis(26,0);
        for(auto x:s) vis[x-'a']++;
        
        unordered_set<int> st;
        int ans=0;
        for(int i=0;i<26;i++){
            while(vis[i]>0&&st.find(vis[i])!=st.end()){
                vis[i]--;
                ans++;
            }
            st.insert(vis[i]);
        }
        return ans;
        
    }
};