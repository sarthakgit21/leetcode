class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int> left(n),right(n);
        left[0]=v[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],v[i]);
        }
        right[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(left[i],right[i])-v[i]);
        }
        return ans;
    }
};