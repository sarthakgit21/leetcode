class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        
        int prev=points[0][1];
        
        
        for(int i=1;i<points.size();i++){
            if(prev<points[i][0]){
                ans++;
                prev=points[i][1];
            }
            else{
                prev=min(prev,points[i][1]);
            }
        }
        
        
        return ans;
    }
};