class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    
    bool canDone(int row, int col, vector<vector<int>>& cells,int mid){
        queue<pair<int,int>> q;
        vector<vector<int>> grid(row,vector<int> (col,0));
        for(int i=0;i<mid;i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
        for(int i=0;i<col;i++){
            if(grid[0][i]==0){
                grid[0][i]=1;
                q.push({0,i});
            }
        }
        while(!q.empty()){
            int krow=q.front().first;
            int kcol=q.front().second;
            q.pop();
            if(krow==row-1) return true;
            for(int i=0;i<4;i++){
               int nrow=krow+dx[i]; 
               int ncol=kcol+dy[i];
                if(nrow<0||ncol<0||nrow>=row||ncol>=col||grid[nrow][ncol]==1) continue;
                grid[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
            
        }
        return false;
        
    }
    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0,ans=0;
        int r=cells.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(canDone(row,col,cells,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    
    
};