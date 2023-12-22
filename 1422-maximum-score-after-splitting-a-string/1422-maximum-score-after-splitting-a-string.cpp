class Solution {
public:
    int maxScore(string s) {
        int z=!(s[0]-'0');
        int n=s.size();
        int ans=0;
        int o=0;
        for(auto x:s) o+=(x-'0');
        for(int i=1;i<n;i++){
            int val=z+(o-(i-z));
            ans=max(ans,val);
            z+=!(s[i]-'0');
        }
        
        
        return ans;
    }
};