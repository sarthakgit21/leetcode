class Solution {
public:
    double t[101][101];
    double fun(int poured,int i,int j){
        
        if(i<0||j<0||i<j) return 0.0;
        if(i==0&&j==0) return poured;
        if(t[i][j]!=-1) return t[i][j];
        auto left=(fun(poured,i-1,j)-1)/2.0;
        auto right=(fun(poured,i-1,j-1)-1)/2.0;
        
        if(left<0) left=0;
        if(right<0) right=0;
        
        return t[i][j]=left+right;
        
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                t[i][j]=-1;
            }
        }
        return min(1.0,fun(poured,query_row,query_glass));
    }
};