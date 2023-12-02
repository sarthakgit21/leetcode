class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> mp;
        for(auto x:chars){
            mp[x]++;
        }
        int ans=0;
        for(auto x:words){
            map<char,int> mpp;
            for(auto c:x){
                mpp[c]++;
            }
            int gg=0;
            for(auto [i,j]:mpp){
                // cout<<i<<j<<endl;
                if(j>mp[i]){
                    gg=1;
                    break;
                }
            }
            if(!gg) ans+=x.size();
        }
        return ans;
    }
};