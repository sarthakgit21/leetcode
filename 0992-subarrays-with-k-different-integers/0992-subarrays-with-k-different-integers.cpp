class Solution {
public:
    int countMaxk(vector<int> &nums,int k){
        int i=0;
        int j=0;
        int ct=0;
        map<int,int> mp;
        int n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                auto it=mp.find(nums[i]);
                it->second--;
                if(it->second==0) mp.erase(it);
                i++;
            }
            ct+=(j-i+1);
            j++;
        }
        return ct;
    }
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countMaxk(nums,k)-countMaxk(nums,k-1);
    }
};