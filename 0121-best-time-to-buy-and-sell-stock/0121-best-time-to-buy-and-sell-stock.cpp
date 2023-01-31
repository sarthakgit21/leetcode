class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int mn=INT_MAX;
        int ans=0;
        for(auto x:prices){
            mn=min(mn,x);
            ans=max(ans,x-mn);
        }
        return ans;
    }
};