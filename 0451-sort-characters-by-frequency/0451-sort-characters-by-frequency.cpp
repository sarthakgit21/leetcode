class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto x:s) mp[x]++;
        string ans="";
        priority_queue<pair<int,char>> pq;
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        while(!pq.empty()){
            for(int i=0;i<(pq.top().first);i++)
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;
    } 
};