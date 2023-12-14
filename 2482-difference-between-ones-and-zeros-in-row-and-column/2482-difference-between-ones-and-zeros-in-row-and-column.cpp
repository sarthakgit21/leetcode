class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> row(n,0);
        vector<int> col(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                int val=(col[j]+row[i])-(n-row[i])-(m-col[j]);
                v.push_back(val);
            }
            ans.push_back(v);
        }
        
        return ans;
        
    }
};