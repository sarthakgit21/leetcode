class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1),hash(n,1);
        int maxind=0;
        int val=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0&&dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                                 if(dp[i]>val){
                val=dp[i];
                maxind=i;
            }
                }
               
            }

            
        }
        vector<int> ans;
        ans.push_back(arr[maxind]);
        while(hash[maxind]!=maxind){
            maxind=hash[maxind];
            ans.push_back(arr[maxind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};