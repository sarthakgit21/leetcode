class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int c=0;
        for(int i:nums){
            if(i==1){
                c++;
                continue;
            }
            else{
                ans=max(ans,c);
                c=0;
            }
           
        }
        ans=max(ans,c);
        return ans;
    }
    
};