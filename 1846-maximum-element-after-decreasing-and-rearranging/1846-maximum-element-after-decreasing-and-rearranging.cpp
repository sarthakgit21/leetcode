class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans=0;
        sort(arr.begin(),arr.end());
        int val=1;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>val){
                val++;
            }
        }
        return val;
    }
};