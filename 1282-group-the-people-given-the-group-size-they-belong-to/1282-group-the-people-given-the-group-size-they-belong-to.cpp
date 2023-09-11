class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<vector<int>> ans;
        
        for(auto x:mp){
            
            auto vec=x.second;
            auto val=x.first;
            
            int num=vec.size()/val;
            
            for(int i=0;i<vec.size();){
                vector<int> v;
                int k=val;
                for(;i<vec.size()&&k>0;i++){
                    v.push_back(vec[i]);
                    k--;
                }
                ans.push_back(v);
                
            }
        }
        return ans;
        
    }
};