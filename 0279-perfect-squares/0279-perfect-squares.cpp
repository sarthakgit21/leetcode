class Solution {
public:
    
    bool isquare(int i)
    {
        int val=sqrt(i);
        if(val*val==i) return true;
        return false;
    }
    int dp[101][10001];
    int fun(int ind,int n,vector<int> &vals)
    {
        if(n==0)
        {
            return 0;
        }
        if(ind>=vals.size())
        {
            return 1e9;
        }
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int one=INT_MAX;
        if(n>=vals[ind]){
            one=1+fun(ind,n-vals[ind],vals);
        }
        int last=fun(ind+1,n,vals);
        // cout<<one<<" "<<last<<endl;
        return dp[ind][n]=min(one,last);
        
        
        
    }
    
    int numSquares(int n) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        vector<int> vals;
        for(int i=1;i*i<=n;i++)
        {
             vals.push_back(i*i);
        }
        ans=fun(0,n,vals);
        return ans;
        
    }
};