class Solution {
public:
    const int mod=1e9+7;
    int countHomogenous(string s) {
        long long cnt=0;
        char prev='?';
        s.push_back('?');
        long long ans=0;
        for(auto x:s){
            if(prev==x){
                cnt++;
            }
            else{
                ans+=(cnt*(cnt+1))/2;
                ans%=mod;
                prev=x;
                cnt=1;
            }
        }
        return (int)ans;
    }
};