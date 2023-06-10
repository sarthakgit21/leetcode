#define ll long long
class Solution {
public:
    ll sum(ll ele,ll x){
        return x*ele-(ele*(ele+1))/2;
    }
    int maxValue(int n, int i, int maxSum) {
        ll ans=0,s=0,h=INT_MAX;
        while(s<=h){
            ll mid=(h-s)/2+s;
            ll l=sum(min((ll)i,mid-1),mid);
            l+=max((ll)0,i-mid+1);
            
            ll r=sum(min((ll)n-i-1,mid-1),mid);
            r+=max((ll)0,n-i-1-mid+1);
            if(l+r+mid<=maxSum){
                s=mid+1;
                ans=max((ll)ans,mid);
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};