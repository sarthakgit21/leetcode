class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool left=false;
        bool right=false;
        
        for(int i=1;i<n;i++){
            
            if(nums[i-1]<nums[i]) left=true;
            else if(nums[i-1]>nums[i])right=true;
            
            if(left==true){
                if(right==true) return false;
            }
            if(right==true){
                if(left==true) return false;
            }
            
        }
        
        return true;
    }
};