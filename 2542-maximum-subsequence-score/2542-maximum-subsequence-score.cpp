class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={nums2[i],nums1[i]};
        }
        sort(v.rbegin(),v.rend());
        long cur=0;
        long ans=0;
        priority_queue<int,vector<int> ,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(v[i].second);
            cur+=v[i].second;
            if(pq.size()>k){
                int val=pq.top();
                pq.pop();
                cur-=val;
            }
            if(pq.size()==k) ans=max(ans,cur*v[i].first);
        }
        return ans;
        
        
    }
};