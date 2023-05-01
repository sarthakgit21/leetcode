class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int j=0;
        int ans=0;
        int c=0;
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp['a']>=1&&mp['b']>=1&&mp['c']>=1){
                ans+=(n-i);
                mp[s[j]]--;
                j++;
            }
        }
        return ans;
    }
};