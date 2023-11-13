class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        string ans,st;
        for(auto x:s){
            if(mp[x]){
                st.push_back(x);
                ans.push_back('?');
            }
            else{
                ans.push_back(x);
            }
        }
        sort(st.begin(),st.end());
        int ind =0;
        // cout<<st<<endl<<ans<<endl;
        for(auto &x:ans){
            if(x=='?'){
                x=st[ind];
                ind++;
            }
        }
        return ans;
    }
};