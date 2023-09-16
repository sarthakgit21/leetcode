class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    bool fun(vector<vector<int>>& heights,int n,int m,int i,int j,vector<vector<int>> &vis,int val){
        
        if(i==n-1&&j==m-1) return true;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<0||y<0||x>=n||y>=m||vis[x][y]==1||abs(heights[x][y]-heights[i][j])>val) continue;
            if(fun(heights,n,m,x,y,vis,val)) return true;
            
        }
        return false;
        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        int maxval=abs(heights[n-1][m-1]-heights[0][0]);
        
        int l=0;
        int h=1e9;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            vector<vector<int>> vis(n,vector<int> (m,0));
            if(fun(heights,n,m,0,0,vis,mid)){
                ans=mid;
                // cout<<mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};