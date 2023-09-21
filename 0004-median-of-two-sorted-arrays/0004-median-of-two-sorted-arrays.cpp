class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int low=0;
        int high=n;
        while(low <= high){
            int cut1=((low+high)/2);
            int cut2=((n+m+1)/2-cut1);
            int left1 = cut1==0?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0?INT_MIN:nums2[cut2-1];
            int right1 = cut1==n?INT_MAX:nums1[cut1];
            int right2 = cut2==m?INT_MAX:nums2[cut2];
            if(left1<=right2&&left2<=right1){
                if((n+m)%2==0){
                    return  (max(left1,left2)+ min(right1,right2))/2.0;
                }
                else{
                    return max(left1,left2);
                }
            }
            if(left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
            
        }
        return 0.0;
        
    }
};