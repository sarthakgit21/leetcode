class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        map<int,vector<int>> mp;
        for(auto vec:adjacentPairs){
            int x=vec[0];
            int y=vec[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        int str=-1;
        int str2=-1;
        
        for(auto x:mp){
            if(x.second.size()==1){
                if(str==-1)
                    str=x.first;
                else
                    str2=x.first;
            }
        }
        map<int,int> chk;
        
        ans.push_back(str);
        chk[str]=1;
        int n=adjacentPairs.size();
        while(ans.size()<n){
            int sz=ans.size()-1;
            auto vec=mp[ans[sz]];
            for(auto x:vec){
                // cout<<x<<" ";
                if(chk.count(x)){
                    continue;
                }
                else{
                    ans.push_back(x);
                    chk[x]=1;
                    break;
                }
            }
            // cout<<endl;
        }
        ans.push_back(str2);
        
        return ans;
    }
};