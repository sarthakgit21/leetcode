class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        
        while(columnNumber>0)
        {
            columnNumber--;
            int val=columnNumber%26;
            ans+=('A'+val);
            columnNumber-=val;
            columnNumber/=26;

        }
        reverse(begin(ans),end(ans));
       
        
        return ans;
    }
};