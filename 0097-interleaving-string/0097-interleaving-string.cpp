class Solution {
public:
    int dp[101][101][201];
    bool find(int s1i,int s2i,int ind,string s1, string s2, string s3,int flag)
    {
        if(ind>=s3.size()) return s2i>=s2.size()&&s1i>=s1.size();
        if(dp[s1i][s2i][ind]!=-1) return dp[s1i][s2i][ind];
        bool ans=false;
        if(s1[s1i]==s3[ind])
        {
            ans|= find(s1i+1,s2i,ind+1,s1,s2,s3,1);
        }
        
        if(s2[s2i]==s3[ind])
        {
            ans|= find(s1i,s2i+1,ind+1,s1,s2,s3,0);
        }
        
        return dp[s1i][s2i][ind]=ans;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,s1,s2,s3,0)||find(0,0,0,s2,s1,s3,0);
    }
};