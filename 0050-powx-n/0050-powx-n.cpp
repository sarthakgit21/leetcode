class Solution {
public:
    double myPow(double x, int n) {
       double ans=1;
       long long nn=abs(n);
        // nn<0?nn=-n:nn=n;
        
        while(nn){
            if(nn&1){
                ans=ans*x;
            }
            x*=x;
            nn>>=1;
        }
        return n<0?1/ans:ans;
    }
};