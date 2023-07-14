class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff ) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=1+mp[arr[i]-diff];
            ans=max(ans,mp[arr[i]]);
        }
        return ans;
        
    }
};