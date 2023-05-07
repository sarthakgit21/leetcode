class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res(obstacles.size(), 1);
        vector<int> v;
        for(int i=0; i<obstacles.size(); i++) {
            int tr = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin(); 
            if (tr == v.size())
                v.push_back(obstacles[i]);
            else
                v[tr] = obstacles[i];
            
            res[i] = tr + 1;
        }
        return res;
    }
};
