class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        int val=n;
        
        int i=0;
        while(i<n){
            if(i+1<n&&nums[i]==nums[i+1]){
                i++;
                continue;
            }
            int ind=1;
            while(i+1<n&&nums[i]<nums[i+1]){
                val+=ind;
                ind++;
                i++;
            }
            int ind2=1;
            cout<<val<< " ";
            while(i+1<n&&nums[i]>nums[i+1]){
                val+=ind2;
                ind2++;
                i++;
            }
            cout<<ind2<<" "<<ind<<endl;        
            // if(ind>1&&ind2>1)
            val-=min(ind-1,ind2-1);
            if(i>=n-1) break;

        }
        
        return val;
        
    }
};