class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> mp;
        for(auto x:paths){
            mp[x[0]]++;
        }
        
        for(auto x:paths){
            if(mp.count(x[1])==0) return x[1];
        }
        
        return "";
    }
};