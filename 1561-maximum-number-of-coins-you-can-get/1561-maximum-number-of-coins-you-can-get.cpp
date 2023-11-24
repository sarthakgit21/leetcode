class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(begin(piles),end(piles));
        int n=piles.size();
        for(int i=(n/3);i<n;i+=2) ans+=(piles[i]);
        return ans;
    }
};