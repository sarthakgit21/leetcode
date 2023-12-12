class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=*max_element(begin(nums),end(nums));
        int maxi2=1;
        int n=0;
        
        for(auto x:nums){
            if(maxi1>x){
                maxi2=max(maxi2,x);
                // cout<<maxi2;
            }
            if(x==maxi1) n++; 
        }
        
        
        maxi1--;
        maxi2--;
        if(n>=2) maxi2=maxi1;
        return maxi1*maxi2; 
    }
};