class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<int,int> mp;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                ans=max(ans,i-mp[s[i]]);
                // cout<<mp[s[i]]<<i;
                continue;
            }
            mp[s[i]]=i;
        }
        return ans-1;
    }
};