class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=0;
        int val=0;
        for(auto x:nums){
            if(x==0) return 0;
            if(x<0) val++;
        }
        if(val&1) return -1;
        return 1;
    }
};