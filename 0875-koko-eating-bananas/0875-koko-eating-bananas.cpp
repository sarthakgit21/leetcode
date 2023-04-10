class Solution {
public:
    bool pos(vector<int> &arr,int mid,int h){
        int val=0;
        if(mid==0) return false;
        for(auto x:arr){
            int num=x/mid;
            if(x%mid!=0){
                num++;
            }
            if(val>h) return false;
            val+=num;
        }
        return val<=h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=0;
        int j=1e9;
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(pos(piles,mid,h)){
                cout<<ans<<" "<<mid<<endl;
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};