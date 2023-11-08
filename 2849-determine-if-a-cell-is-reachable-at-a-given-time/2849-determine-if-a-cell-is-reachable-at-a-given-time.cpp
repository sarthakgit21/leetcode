class Solution {
public:
    
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        
        int val=min(x,y)+abs(y-x);
        // cout<<val;
        if(val==0) return t!=1;
        return val<=t;
        
    }
};