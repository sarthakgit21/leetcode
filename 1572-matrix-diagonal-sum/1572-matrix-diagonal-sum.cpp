class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0 ;
        int j=mat[0].size()-1;
        for(int i =0;i<mat.size();i++){
            ans=ans+mat[i][i]; 
            if(i!=j) ans=ans+mat[i][j];    
            j--;
        }
        return ans;
    }
};