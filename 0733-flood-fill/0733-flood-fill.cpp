class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int n=arr.size();
        int m=arr[0].size();
        int iniColor=arr[sr][sc];
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[sr][sc]=1;
        arr[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[5]={0,-1,0,1,0};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dx[i+1];
                if(newx<0||newy<0||newx>=n||newy>=m||arr[newx][newy]==color||vis[newx][newy]==1||arr[newx][newy]!=iniColor) continue;
                arr[newx][newy]=color;
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
        return arr;
    }
};