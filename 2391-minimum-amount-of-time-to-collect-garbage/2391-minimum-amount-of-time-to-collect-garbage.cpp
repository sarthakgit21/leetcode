class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int m=travel.size();
        vector<int> pre(n,0);
        pre[0]=0;
        for(int i=1;i<m;i++){
            travel[i]+=travel[i-1];
        }
        int i=0;
        map<char,int> mp;
        map<char,int> ind;
        for(auto x:garbage){
            for(auto c:x){
                mp[c]++;
                ind[c]=i;
            }
            i++;
        }
        int ans=0;
        for(auto [x,y]:ind){
            if(y-1>=0)ans+=(travel[y-1]);
            ans+=(mp[x]);
        }
        return ans;
    }
};