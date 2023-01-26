class Solution
{
    public:
        void setZeroes(vector<vector < int>> &m)
        {
            int col1 = 1;
            int r = m.size();
            int c = m[0].size();
            for (int i = 0; i < r; i++)
            {
                if (m[i][0] == 0) col1 = 0;
                for (int j = 1; j < c; j++)
                {
                    if (m[i][j] == 0)
                    {
                        m[i][0] = m[0][j]=0;
                    }
                }
            }
            for (int i = r - 1; i >= 0; i--)
            {
                for (int j = c - 1; j >= 1; j--)
                {
                    if (m[i][0]== 0||m[0][j]==0){
                       m[i][j]=0;
                    }
                }
                if(col1==0) m[i][0]=0;
            }
        }
    
};