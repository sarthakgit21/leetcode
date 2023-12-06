class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int val=0;
        if(n>7){
            val=n/7;
            // val--;
            int x=(val-1)*(val)/2;
            ans+=x*7+val*28;
            // cout<<ans<<endl;
            n%=7;
            // val++;
        }
        ans+=(n*(n+1))/2;
        ans+=(val*n);
        return  ans;
    }
};