class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto c:nums) mp[c]++;
        
        for(auto x:mp){
            if(x.second<2){
                return -1;
            }
            else{
                int val=x.second;
                if(val%3==0){
                    ans+=val/3;
                }
                else if(val%3==1){
                    int num=val/3;
                    num++;
                    ans+=num;
                }
                else{
                    ans+=(val/3);
                    ans+=1;
                }
            }
        }
        
        return ans;
    }
};