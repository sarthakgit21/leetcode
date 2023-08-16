class Solution {
public:
    int countPrimes(int n) {
        vector<bool> res(n+1,true);
        res[0]=false;
        res[1]=false;
        
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(res[i])
            {
                // cout<<i;
                ans++;
                int val=i*2;
                for(int j=val;j<=n;j=j+i)
                {
                    res[j]=false;
                }
            }
            
        }

        return ans;
        
        
        
    }
};