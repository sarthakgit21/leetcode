class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i=0;
        int j=i+1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int mini=1e9;

        int mins=0;
        while(i<n-2){
         
            j=i+1;
            int k=n-1;
            while(j<k){

                long sum=nums[i]+nums[j];
                sum+=nums[k];
                if(abs(target-sum)<mini){
                    mini=abs(target-sum);
                    ans=sum;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
            i++;
    }
        // cout<<mins;
        return ans;
    }
};