class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==0) return ans;
        vector<int> temp=intervals[0];
        for(auto x:intervals){
            if(x[0]<=temp[1]){
                temp[1]=max(temp[1],x[1]);
            }
            else{
                ans.push_back(temp);
                temp=x;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};