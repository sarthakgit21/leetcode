class Solution {
public:
    int titleToNumber(string columnTitle) {
        int val=0;
        int ind =1;
        for(auto x:columnTitle)
        {
            val=val*(26)+(x-'A'+1);
        }
        return val;
    }
};