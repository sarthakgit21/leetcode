class Solution {
public:
    
    int Helper(vector<vector<int>>& graph,int n){
        int fullCap=(1<<n)-1;
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            q.push({i,{0,1<<i}});
            st.insert({i,1<<i});
        }
        
        // int dis=0;
        
        
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            int val=node.first;
            int dist=node.second.first;
            int mask=node.second.second;
            for(auto x:graph[val]){
                
                int nmask=(mask|(1<<x));
                if(nmask==fullCap) return dist+1;
                
                else if(st.count({x,nmask})){
                    continue;
                }
                else{
                    q.push({x,{dist+1,nmask}});
                    st.insert({x,nmask});
                }
            }
        }
        // cout<<"ds";
        return 0;
        
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;
        return Helper(graph,n);
    }
};