class Solution {
public:
    bool pos(vector<int>& bloomDay, int m, int k,int mid){
        // long long val=m*k;
        long long cnt=0;
        vector<int> v;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
                // cout<<bloomDay[i]<<" "<<mid<<endl;
            }
            else{
                if(cnt!=0)
                v.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt!=0) v.push_back(cnt);
        cnt=0;
        for(auto x:v){
            if(x>=k) cnt+=(x/k);
            // cout<<x<<endl;
        }
        return cnt>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int i=0;
        int j=1e9;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            // cout<<mid<<endl;
            if(pos(bloomDay,m,k,mid)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
            // cout<<"i"<<i<<' '<<'j'<<j<<endl;
        }
        return ans;
    }
};