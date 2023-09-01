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
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(findBits(i));
        }
        return ans;
    }
};