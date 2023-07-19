class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int ans=0;
        vector<int> L=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(L[1]<=intervals[i][0]){
                L=intervals[i];
                continue;
            }
            else if(L[1]<=intervals[i][1]){
                ans++;
            }
            else{
                ans++;
                L=intervals[i];
            }
        }
        return ans;
    }
};