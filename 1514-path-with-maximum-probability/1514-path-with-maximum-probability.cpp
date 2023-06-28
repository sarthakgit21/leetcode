class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans=0;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
        vector<double> prob(n,0);
        prob[start]=1;
        while(!pq.empty()){
            int pos=pq.top().second;
            double cnt=pq.top().first;
            pq.pop();
            for(auto it:adj[pos]){
                if(it.second*cnt>prob[it.first]){
                    prob[it.first]=(double)it.second*cnt;
                    pq.push({prob[it.first],it.first});
                }
            }
            
        }
        return prob[end];
                
    }
};