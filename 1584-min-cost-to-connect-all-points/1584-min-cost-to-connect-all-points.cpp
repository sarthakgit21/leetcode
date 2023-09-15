class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x]);
    }
    
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        
        parent.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        
        int ans=0;
        
        vector<vector<int>> v;
        
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int d = abs(x1-x2) + abs(y1-y2);
                
                
                v.push_back({i, j, d});
            }
        }
        
        auto cmp=[&](vector<int> &a,vector<int>&b){
            return a[2]<b[2];
        };
        
        sort(v.begin(),v.end(),cmp);
        
        return fun(v);
        
    }
    
    int fun(vector<vector<int>>&v){
        int ans=0;
        for(auto x:v){
            int a=x[0];
            int b=x[1];
            int c=x[2];
            
            if(find(a)!=find(b)){
                Union(a,b);
                ans+=c;
            }
            
        }
        return ans;
    }
};