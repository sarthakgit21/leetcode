class Solution {
public:
    void sortColors(vector<int>& nums) {
     int l=0;
        int mid=0;
        int h=nums.size()-1;
        while(mid<=h){
            switch(nums[mid]){
                case 0:
                    swap(nums[mid++],nums[l++]);break;
                case 1:
                    mid++;break;
                case 2:
                    swap(nums[mid],nums[h--]);break;
                    
            }
        }
    }
};