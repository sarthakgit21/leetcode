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
        fun(s);
        fun(t);
        return t==s;
    }
};