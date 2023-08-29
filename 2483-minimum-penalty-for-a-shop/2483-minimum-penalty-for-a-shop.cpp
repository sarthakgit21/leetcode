class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=INT_MAX;
        int maxi=INT_MAX;
        int n=customers.size();
        vector<int> left(n+1,0);
        vector<int> right(n+1,0);
        if(customers[0]=='Y') left[0]=0;
        else left[0]=1;
        for(int i=1;i<=n;i++)
        {
            left[i]=left[i-1]+(customers[i]=='N'?1:0);
        }
        right[n]=0;
        if(customers[n-1]=='Y') right[n-1]=1;
        else right[n-1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            right[i]=right[i+1]+(customers[i]=='Y'?1:0);
        }
        // cout<<right[0];
         maxi=right[0];
        ans=0;
        
//         for(int i=0;i<=n;i++)
//         {
//             cout<<left[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i=0;i<=n;i++)
//         {
//             cout<<right[i]<<" ";
//         }
        for(int i=1;i<=n;i++)
        {
            if(right[i]+left[i-1]<maxi)
            {
                maxi=right[i]+left[i-1];
                // cout<<maxi<<" "<<i<<endl;
                ans=i;
            }
        }
        
        
        return ans;
    }
};