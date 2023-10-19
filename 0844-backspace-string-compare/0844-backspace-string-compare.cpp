class Solution {
public:
    void fun(string &s){
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(ans.size()) ans.pop_back();
            }
            else{
                ans+=s[i];
            }
        }
        s=ans;
    }
    bool backspaceCompare(string s, string t) {
       int n=s.size();
       int m=t.size();
        int ind1=0,ind2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                ind1--;
                ind1=max(0,ind1);
            }
            else{
                s[ind1++]=s[i];
            }
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#'){
                ind2--;
                ind2=max(0,ind2);
            }
            else{
                t[ind2++]=t[i];
            }
        }
        if(ind1!=ind2) return false;
        // cout<<s<<t;
        for(int i=0;i<ind1;i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};