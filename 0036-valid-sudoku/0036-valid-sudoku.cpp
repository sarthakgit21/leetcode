class Solution {
public:
    bool  isSafe(vector<vector<char>>&board,int row,int col,char value,int n){
        board[row][col] = '#';
        for(int i=0;i<n;i++){
            //for row
            if(board[row][i]==value){ 
                return false;
            }

            //for col
            if(board[i][col]==value){ 
                return false;
            }

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value){
                return false;
            }
        }
        board[row][col] = value;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
           int n=board.size();
        // bool ans= solve(board);
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(board[i][j]!='.')
                 {
                     if(!isSafe(board,i,j,board[i][j],9)) return false;
                 }
            }
             // cout<<endl;
         }
        
        return true;
    }
};