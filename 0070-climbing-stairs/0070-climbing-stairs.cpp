class Solution {
    
public:
    
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n<=2) return n;
        int prev2=2,prev=1,res=0;
        for(int i=3;i<=n;i++){
            res=prev+prev2;
            prev=prev2;
            prev2=res;
            }
        return res;
        
    }
};