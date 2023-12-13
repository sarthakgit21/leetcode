class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        int valk=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int g=1;
                    for(int k=0;k<n;k++){
                        if(i!=k && mat[k][j]==1){
                            g=0;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(j!=k && mat[i][k]==1){
                            g=0;
                        }
                    }
                    if(g) ans++;
                }
            }
        }
        return ans;
       
    }
};