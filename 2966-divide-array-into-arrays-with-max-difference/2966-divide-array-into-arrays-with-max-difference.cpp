class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        vector<vector<int>> ans;
        int n=nums.size();
            vector<int> v;
        int prev=-1;
        for(int i=0;i<nums.size();i+=3){
            vector<int> v;
            for(int j=i;j<(i+3);j++){
                v.push_back(nums[j]);
                if(j>i && nums[j]-nums[j-1]>k) return {};
                if(j>i+1 && nums[j]-nums[j-2]>k) return {};
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};