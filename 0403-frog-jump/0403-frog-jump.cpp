class Solution {
public:
    int dp[2001][2001];
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
            int jump=i+k;
            if (jump==0) continue;
            //Use binary search, since stones[i] is ascending
            int next=lower_bound(stones.begin()+(ind+1), stones.end(), stones[ind]+jump)
                -stones.begin();
            if (next==stones.size() || stones[next]!=stones[ind]+jump) continue; // not found
            ans=ans||fun(stones, next, jump);
        }
        
        return dp[ind][k]=ans;
        
    }
    
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return fun(stones,0,0);
    }
};