class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=coins.size();
        
        int ans=0;;
        
        long long val=0;
        sort(begin(coins),end(coins));
        int ind=0;
        for(int i=1;i<=target;i++){
            if(ind<n && coins[ind]<=i){
                val+=coins[ind];
                ind++;
            }
            else{
                if(val>=i) continue;
                val+=i;
                ans++;
            }
        }
        
        return ans;
    }
};