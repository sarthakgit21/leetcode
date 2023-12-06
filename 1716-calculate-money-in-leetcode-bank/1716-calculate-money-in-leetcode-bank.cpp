class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int val=0;
        while(n>7){
            ans+=val*7+28;
            val++;
            n-=7;
        }
        ans+=(n*(n+1))/2;
        ans+=(val*n);
        return  ans;
    }
};