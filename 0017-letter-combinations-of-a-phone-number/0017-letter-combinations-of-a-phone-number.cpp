class Solution {
public:
    void solve(string &digits,vector<string> &ans,string v,string mp[],int ind){
        if(ind>=digits.size()){
            ans.push_back(v);
            return;
        }
        int val=digits[ind]-'0';
        string ss=mp[val];
        for(int i=0;i<ss.size();i++){
            v.push_back(ss[i]);
            solve(digits,ans,v,mp,ind+1);
            v.pop_back();
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        string v;
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,v,mp,0);
        return ans;
    }
};