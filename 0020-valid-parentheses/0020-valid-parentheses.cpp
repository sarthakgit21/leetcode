class Solution {
public:
    bool isValid(string s) {
        map<char,char> mp;
        mp['(']=')';
        mp['[']=']';
        mp['{']='}';
        stack<char> st;
        for(auto x:s){
            if(mp.count(x)){
                st.push(x);
                continue;
            }
            else{
                if(st.empty()) return false;
                if(x!=mp[st.top()]){
                    return false;
                }
                st.pop();
                continue;
            }
        }
        return st.empty();
    }
};