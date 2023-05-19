class Solution {
public:
    bool vis[105];
    bool color[105];
    bool dfs(vector<vector<int>>& graph,int v,bool vis[],int c){
        vis[v]=1;
        color[v]=c;
        for(auto it: graph[v]){
            if(!vis[it]){
                if(dfs(graph,it,vis,c^1)==false) return false;
            }
            else{
                if(color[it]==color[v]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            if(color[i]==0&&dfs(graph,i,vis,0)==false) return false;
        }
        return true;
    }
};