class Solution {
public:
    int dp[301];
    bool fun(set<string> &worddict,string &s,int ind){
        if(s.size()==ind) return 1;
        if(dp[ind]!=-1) return dp[ind];
        string temp;
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            // cout<<temp<<endl;
            if(worddict.find(temp)!=worddict.end()){
                if(fun(worddict,s,i+1)) return dp[ind]=1;
            }
        }
            return dp[ind]=0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> setStrings;
        memset(dp,-1,sizeof dp);
        for(auto x:wordDict) setStrings.insert(x);
        return fun(setStrings,s,0);
    }
};