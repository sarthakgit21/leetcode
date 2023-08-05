class Solution {
public:
    int vis[7][7];
    bool findWord(vector<vector<char>>& board, string word,string &s,int n,int m,int i,int j)
    {
        vis[i][j]=1;
        s+=board[i][j];
        if(s==word){
            return true;
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            int nextX=i+dx[k];
            int nextY=j+dy[k];
            if(nextX<0||nextY<0||nextX>=n||nextY>=m||(!s.empty()&&board[nextX][nextY]!=word[s.size()])||vis[nextX][nextY]) continue;
            
            if((findWord(board,word,s,n,m,nextX,nextY))) return true;
            
        }
        vis[i][j]=0;
        s.pop_back();
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        memset(vis,0,sizeof(vis));
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                {
                    string s="";
                    if(findWord(board,word,s,n,m,i,j)) return true;
                    
                }
            }
        }
        
        return false;
        
    }
};