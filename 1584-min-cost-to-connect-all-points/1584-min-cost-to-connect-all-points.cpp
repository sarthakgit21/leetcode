class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> mp;
        
        int n=points.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                mp[i].push_back({j,dis});
            }
        }
        
//         for(auto x:mp){
//             cout<<x.first<<" -";
//             for(auto d:x.second){
//                 cout<<d.first<<" "<<d.second<<" ,";
//             }
//             cout<<endl;
//         }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        int ans=0;
        
        vector<bool> vis(n,false);
        while(!q.empty()){
            int node=q.top().second;
            int dis =q.top().first;
            q.pop();
            // cout<<dis<<endl;
            if(vis[node]==true) continue;
            vis[node]=true;
            ans+=dis;
            // cout<<node<< " "<<dis<<endl;
            for(auto x:mp[node]){
                int adjnode=x.first;
                int dist=x.second;
                if(vis[adjnode]==false){
                    // cout<<adjnode<<endl;
                    q.push({dist,adjnode});
                }
                
            }
        }
        
        return ans;
        
    }
};