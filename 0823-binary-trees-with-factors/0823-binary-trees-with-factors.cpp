#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
       ll ans=0;
        sort(begin(arr),end(arr));
        unordered_map<ll,ll> mp;
        mp[arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j])!=mp.end()){
                    mp[arr[i]]+=((mp[arr[i]/arr[j]])*mp[arr[j]]);
                    mp[arr[i]]% mod;
                }
            }
        }
        
        for(auto x:mp){
            ans+=(x.second);
            ans%=mod;
        }
        return ans;
    }
};