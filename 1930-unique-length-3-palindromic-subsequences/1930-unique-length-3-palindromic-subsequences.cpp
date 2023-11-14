class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        
        for(auto [x,y]:mp){
            if(y.size()>=2){
                int sz=y.size();
                int lastInd=y[sz-1];
                int firstInd=(y[0]);
                for(auto [a,b]:mp){
                    auto it=upper_bound(b.begin(),b.end(),firstInd);
                    if(it!=b.end()){
                        int valOfInd=*it;
                        if(valOfInd<lastInd){
                            ans++;
                        }
                    }
                }
            }

        }
        
        return ans;
    }
};