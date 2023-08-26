class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto comp=[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        };
        
        sort(pairs.begin(),pairs.end(),comp);
        
        // for(auto x:pairs)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        int ans=1;
        int lastval=pairs[0][1];
        int n=pairs.size();
        for(int i=1;i<n;i++)
        {
            if(pairs[i][0]>lastval)
            {
                ans++;
                lastval=pairs[i][1];
            }

        }
        
        return ans;
        
    }
};