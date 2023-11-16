class Solution {
public:
    
    
    string ans;
    void dfs(int n,unordered_map<string,int> &mp,int ind,string &s){
        if(mp.find(s)==mp.end()) {ans=s;return ;}
        if(ind>=n) return ;
        s[ind]='1';
        dfs(n,mp,ind+1,s);
        s[ind]='0';
        dfs(n,mp,ind+1,s);
        return;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> mp;
        for(auto x:nums) mp[x];
        int n=nums.size();
        string s(n,'0');
        dfs(n,mp,0,s);
        return ans;
        
    }
};