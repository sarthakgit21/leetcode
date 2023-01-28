class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int  n=v.size();
        int k,l;
        for(k=n-2;k>=0;k--){
            if(v[k]<v[k+1]) break;
        }
        if(k<0) reverse(v.begin(),v.end());
        else {
            // if(k>=0)
                for(l=n-1;l>k;l--){
                    if(v[l]>v[k]) break;
                }
                swap(v[l],v[k]);
                reverse(v.begin()+k+1,v.end());
            }
            
    }
};