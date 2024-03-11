class Solution {
public:
    string customSortString(string order, string s) {
        map<int,char> mp;
        map<char,int> mps;
        int i=0;
        for(auto x:order) mp[i++]=x;
        for(auto x:s) mps[x]++;
        string ans="";
        for(auto x:mp){
            if(mps.count(x.second)){
                string val(mps[x.second],x.second);
                // cout<<x.first<<x.second;
                mps[x.second]=0;
                ans+=(val);
            }
        }
        for(auto x:mps){
            if(x.second==0) continue;
            string  val(x.second,x.first);
            ans+=(val);
        }
        return ans;
        
        
    }
};