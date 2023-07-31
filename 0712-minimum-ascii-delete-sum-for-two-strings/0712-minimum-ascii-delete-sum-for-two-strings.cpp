class Solution {
public:
    
    int dp[1001][1001];
    
    int minimumDeleteSum(string s1, string s2) {
        
        memset(dp,-1,sizeof(dp));
        
        return fun(s1,s2,0,0);
    }
    
    int fun(string &s1,string &s2,int i ,int j)
    {
        if(i>=s1.size()&&j>=s2.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i>=s1.size()) return dp[i][j]=s2[j]+fun(s1,s2,i,j+1);
        
        if(j>=s2.size()) return dp[i][j]=s1[i]+fun(s1,s2,i+1,j);
        
        if(s1[i]==s2[j]) return dp[i][j]=fun(s1,s2,i+1,j+1);
        
        int take=s1[i]+fun(s1,s2,i+1,j);
        
        int not_take=s2[j]+fun(s1,s2,i,j+1);
        
        return dp[i][j]=min(take,not_take);
    }
    
};