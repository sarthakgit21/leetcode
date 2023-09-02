class Solution {
public:
    int t[51];
    int fun(string s, set<string>& dict,int ind)
    {
        if(ind>=s.size()) return 0;
        if(t[ind]!=-1) return t[ind];
        string val;
        int ans=1e9;
        for(int i=ind;i<s.size();i++)
        {
            val+=s[i];
            int vals=0;
            if(dict.find(val)==dict.end()){
                vals=val.size();
            }
            int nextval=fun(s,dict,i+1);
            ans=min(ans,vals+nextval);
            
        }
        return t[ind]=ans;
        
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(t,-1,sizeof(t));
        set<string> vals(dictionary.begin(),dictionary.end());
        unordered_map<string,int> mp;
        for(auto x:dictionary) mp[x]++;
        int n=s.size();
        vector<int> dp(n+1,1e9);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int mini=s.size();
            string ss;
            for(int j=i;j<n;j++){
                ss.push_back(s[j]);
                int val=0;
                if(mp[ss]==0){
                    val=ss.size();
                }
                int val2=dp[j+1];
                mini=min(mini,val+val2);
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};