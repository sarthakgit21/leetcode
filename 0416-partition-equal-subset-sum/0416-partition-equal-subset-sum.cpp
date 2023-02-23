class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum&1) return false;
        sum/=2;
        int n=nums.size();
        vector<vector<bool>> res(n,vector<bool> (sum+1,false));
        for(int i=0;i<n;i++) res[i][0]=true;
        for(int i=1;i<n;i++){
            for(int s=1;s<=sum;s++){
                bool l=res[i-1][s];
                bool r=false;
                if(s>=nums[i]){
                    r=res[i-1][s-nums[i]];
                }
                res[i][s]=l+r;
            }
        }
        return res[n-1][sum];
    }
};