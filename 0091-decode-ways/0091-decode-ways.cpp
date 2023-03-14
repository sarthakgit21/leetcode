class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(101);
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=s.size();i++){
            int k=s[i-1]-'0';
            int kk=10*(s[i-2]-'0')+(s[i-1]-'0');
            if(k>=1) dp[i]+=dp[i-1];
            if(kk>=10&&kk<=26) dp[i]+=dp[i-2];
        }
        return dp[s.size()];
    }
};