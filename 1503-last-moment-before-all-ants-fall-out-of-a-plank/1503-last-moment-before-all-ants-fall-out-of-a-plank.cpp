class Solution {
public:
    int getLastMoment(int n, vector<int>& right, vector<int>& left) {
        sort(begin(left),end(left));
        sort(begin(right),end(right),greater<int>());
        
        int maxi1=0;
        int maxi2=0;
        
        if(left.size()) maxi1=n-left[0];
        if(right.size()) maxi2=right[0];
        
        return max(maxi1,maxi2);
        
    }
};