class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]<=2){
                nums[j]=nums[i];
                j++;
            }
            else{
                continue;
            }
        }
        return j;
    }
};