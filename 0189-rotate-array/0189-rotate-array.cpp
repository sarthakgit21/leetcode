class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k=k%nums.size();
        int n=nums.size();
        int ind=0;
        reverse(begin(nums),end(nums));
        
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());

        
        return;
    }
};