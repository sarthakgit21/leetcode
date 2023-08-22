class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        
        while(columnNumber>0)
        {
            int val=columnNumber%26;
            if(val==0) ans+='Z',val=26;
            else
            ans+=('A'+val-1);
            columnNumber-=val;
            columnNumber/=26;

        }
        reverse(begin(ans),end(ans));
       
        
        return ans;
    }
};