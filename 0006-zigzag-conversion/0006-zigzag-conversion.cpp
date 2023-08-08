class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        
        if(1==numRows||s.size()==0) return s;
        
        vector<string> V(numRows,"");
        
        int i=0;
        int sz=s.size();
        int val=0;
        int inx=1;
        while(i<sz)
        {
            V[val].push_back(s[i]);
            if(val==0)
            {
                inx=1;
            }
            else if(val==numRows-1)
            {
                inx=-1;
            }
            val+=inx;
            i++;
            // cout<<val<<inx<<endl;
        }
        for(auto x:V) ans+=x;
        return ans;
        
    }
};