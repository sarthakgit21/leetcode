class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j){
            int val=min(height[i],height[j]);
            int val2=j-i;
            ans=max(ans,val*val2);
            if(height[i]<=height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};