class Solution {
public:
    int dfs(vector<vector<int>>&tree,int node,vector<int>& informTime) {
        if(tree[node].size()==0) return 0;
        int currMax = 0;
        for(int i=0;i<tree[node].size();i++) currMax = max(currMax,informTime[node] + dfs(tree,tree[node][i],informTime));
        return currMax;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //finding the maximum depth of the tree will be our answer.
        //but how to perform bfs or dfs on an array?
        vector<vector<int>>tree(n);
        int ans = 0;
        for(int i=0;i<n;i++) if(manager[i]!=-1) tree[manager[i]].push_back(i);
        for(int i=0;i<tree[headID].size();i++) ans = max(ans,informTime[headID] + dfs(tree,tree[headID][i],informTime));
        return ans;
    }
};