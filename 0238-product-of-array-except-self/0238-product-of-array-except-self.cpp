class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int val=1;
        int flag=0;
        for(auto x:nums){
            if(x==0) x=1,flag++;
            val*=x;
        }
        vector<int> ans;
        for(auto x:nums) {
            if(flag>1)
            {
                ans=vector<int>(nums.size(),0);
                return ans;
            }
            else if(flag==1)
            {
                if(x==0)
                ans.push_back(val);
                else ans.push_back(0);

            }
            else {
                ans.push_back(val/x);
            }
        }
        return ans;
    }
};