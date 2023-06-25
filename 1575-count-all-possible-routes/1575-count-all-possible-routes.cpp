class Solution {
public:
    int mod=1e9+7;
    int fun(vector<int>& locations, int st, int end, int fuel,vector<vector<int>> &dp){
        if(fuel<0) return 0;
        if(dp[st][fuel]!=-1) return dp[st][fuel];
        int ans=0;
        if(st==end) ans++;
        for(int i=0;i<locations.size();i++){
            if(i==st||abs(locations[i]-locations[st])>fuel) continue;
            ans=ans%mod+fun(locations,i,end,fuel-abs(locations[i]-locations[st]),dp)%mod;
        }
        return dp[st][fuel]=ans%mod;
    }
    
    
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int> (fuel+1,-1));
        return fun(locations,start,finish,fuel,dp);
        
    }
};