class Solution {
public:
    set<vector<int>> st;
    
    void fun(vector<int>& nums,int ind){
        if(ind==nums.size()){
            st.insert(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            fun(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        fun(nums,0);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
        
    }
};