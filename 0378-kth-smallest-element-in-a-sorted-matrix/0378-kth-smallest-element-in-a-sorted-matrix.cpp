class Solution {
public:
    
    
    int isValid(vector<vector<int>>& mat, int mid)
    {
        int n=mat.size();
        int m=mat[0].size();
        int val=0;
        for(int i=0;i<n;i++)
        {
            int ind=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            val+=ind;
        }
        
        return val;
        
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int low=mat[0][0];
        int high=mat[n-1][m-1];
        
        int ans=-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(isValid(mat,mid)>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
            
        }
        
        return ans;
        
        
    }
};