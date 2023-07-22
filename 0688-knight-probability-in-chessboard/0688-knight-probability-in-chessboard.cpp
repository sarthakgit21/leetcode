class Solution {
    
private:
    
    unordered_map<string,double> mp;
    
    double possbileMoves(int n, int k, int row, int col)
    {
        if(k==0)
        {
            return 1.0;
        }
        
        string key=to_string(k)+'#'+to_string( row)+'#'+to_string(col  );
        
        if(mp.find(key)!=mp.end()) return mp[key];

        double no_of_moves=0.0;
        
        
        int dx[8]={-1,-2,-2,-1,+1,+2,+2,+1};

        int dy[8]={-2,-1,+1,+2,+2,+1,-1,-2};
        
        for(int i=0;i<8;i++)
        {

            int newx=row+dx[i];

            int newy =col+dy[i];
            
            if(newx>=0 && newy>=0 && newx<n && newy<n)
            {
                
                // cout<<newx<<" "<<newy<<endl;
                
                no_of_moves+=(possbileMoves(n,k-1,newx,newy));
                
            }
            
        }
        
        return    mp[key]=no_of_moves/8.0;
        
        
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        
     
        
        double ans=possbileMoves(n,k,row,column);
        
       return ans;
    }
};