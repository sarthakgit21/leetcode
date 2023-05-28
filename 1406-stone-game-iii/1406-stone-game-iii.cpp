class Solution {
public:
    string stoneGameIII(vector<int>& s ) {
        int n=s.size();
        vector<int> dp(n+1,0);
        int i=n-1;
        while(i>=0){
            int ans=INT_MIN;
            ans=max(ans,s[i]-dp[i+1]);
            if(i+1<n) ans=max(ans,s[i]+s[i+1]-dp[i+2]);
            if(i+2<n) ans=max(ans,s[i]+s[i+1]+s[i+2]-dp[i+3]);
            dp[i]=ans;
            i--;
        }
        
        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
         return "Tie";
    }
};