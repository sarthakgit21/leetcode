class Solution {
public:
    int t[51];
    int fun(string s, set<string>& dict,int ind)
    {
        if(ind>=s.size()) return 0;
        if(t[ind]!=-1) return t[ind];
        string val;
        int ans=1e9;
        for(int i=ind;i<s.size();i++)
        {
            val+=s[i];
            int vals=0;
            if(dict.find(val)==dict.end()){
                vals=val.size();
            }
            int nextval=fun(s,dict,i+1);
            ans=min(ans,vals+nextval);
            
        }
        return t[ind]=ans;
        
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(t,-1,sizeof(t));
        set<string> vals(dictionary.begin(),dictionary.end());
        return fun(s,vals,0);
    }
};