class Solution {
public:
    int findBits(int n)
    {
        int val=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i)){
                val++;
            }
        }
        return val;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++)
        {
            if(i&1)
            {
                ans[i]=ans[i-1]+1;
            }
            else
            {
                ans[i]=ans[i/2];
            }
        }
        return ans;
    }
};