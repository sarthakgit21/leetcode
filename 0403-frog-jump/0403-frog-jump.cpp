class Solution {
public:
    int dp[2001][6003];
    bool fun(vector<int> &stones,int ind,int k)
    {
        if(ind==stones.size()-1)
        {
            return true;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool ans=false;
        
        for(int i=-1;i<=1;i++)
        {
            int val=i+k;
            
            if(val>0)
            {
                for(int j=ind+val;j>ind;j--){
                    if(j<stones.size()&&stones[j]-stones[ind]==val)
                    {
                        ans|=fun(stones,j,val);
                    } 
                }
            }
        }
        
        return dp[ind][k]=ans;
        
    }
    
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return fun(stones,0,0);
    }
};