class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        
        for(int i=5;i*5<=n;i+=5)
        {
            int val=i*5;
            int num_of_fives=0;
            while(val%5==0)
            {
                val/=5;
                num_of_fives++;
            }
            num_of_fives--;
            // cout<<i*5<<" "<<num_of_fives<<endl;
            ans+=num_of_fives;
           
            
        }
        ans+=n/5;
        return ans;
        
    }
};