class Solution {
public:
    int getLastMoment(int n, vector<int>& right, vector<int>& left) {        
        int maxi1=0;
        int maxi2=0;
        
        if(left.size()){
            int minLeft=*min_element(begin(left),end(left));
            maxi1=n-minLeft;
        }
        if(right.size()) {
            int maxRight=*max_element(begin(right),end(right));
            maxi2=maxRight;
        }
        
        return max(maxi1,maxi2);
        
    }
};