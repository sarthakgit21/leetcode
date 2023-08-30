class Solution {
public:
    string fractionToDecimal(int nn, int dd) {
        string ans;
        if(!nn) return "0";
        if(nn>0 ^ dd>0) ans+='-';
        
        long n=labs(nn);
        long d=labs(dd);
        
        long q=n/d;
        long r=n%d;
        ans+=to_string(q);
        map<long,int> mp;
        if(r!=0)
        {
            ans+='.';
            while(r!=0)
            {
                if(mp.count(r))
                {
                    ans.insert(mp[r],"(");
                    ans+=')';
                    break;
                }
                mp[r]=ans.size();
                r=r*10;
                q=r/d;
                r=r%d;
                ans+=to_string(q);
            }
        }
        
        return ans;
    }
};