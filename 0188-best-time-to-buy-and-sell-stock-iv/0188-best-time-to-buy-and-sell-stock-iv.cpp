class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));
        vector<vector<int>> cur(2,vector<int> (k+1,0));
        vector<vector<int>> prev(2,vector<int> (k+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(buy){
                        prev[buy][cap]=max(-prices[i]+cur[0][cap],cur[1][cap]);
                    }
                    else{
                        prev[buy][cap]=max(prices[i]+cur[1][cap-1],cur[0][cap]);
                    }
                }
                
            } 
            cur=prev;
        }
        return prev[1][k];
    }
};