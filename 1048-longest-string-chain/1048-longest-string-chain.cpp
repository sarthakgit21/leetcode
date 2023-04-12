class Solution {
public:
    bool chk(string &a,string &b){
        int  n=a.size();
        int m=b.size();
        if(n!=1+m) return 0;
        int s=0;
        int f=0;
        while(f<n){
            if(a[f]==b[s]) f++,s++;
            else f++;
        }
        return (f==n&&s==m);
    }
    
     bool static cmp(string &a,string &b) {return a.size()<b.size();}
    int longestStrChain(vector<string>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),cmp);
        int ans=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(chk(a[i],a[j])&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
                // if(dp[i])
                ans=max(ans,dp[i]);
            }
        }
        
        return ans;
    }
};