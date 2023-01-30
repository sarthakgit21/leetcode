class Solution {
public:
    int func(vector<int> &dp,int n){
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(dp,n-1)+func(dp,n-2)+func(dp,n-3);
    }
    int tribonacci(int n){

        vector<int> dp(n+1,-1);
        return func(dp,n);
    }
};