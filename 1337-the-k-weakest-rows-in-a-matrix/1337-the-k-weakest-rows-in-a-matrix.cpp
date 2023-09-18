class Solution {
public:
    
    int BSonarr(vector<int> arr){
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==0){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans(k);
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<n;i++){
            pq.push({BSonarr(mat[i]),i});
            // cout<<BSonarr(mat[i]);
            if(pq.size()>k) pq.pop();
        }
        
        while(!pq.empty()){
            ans[--k]=pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};