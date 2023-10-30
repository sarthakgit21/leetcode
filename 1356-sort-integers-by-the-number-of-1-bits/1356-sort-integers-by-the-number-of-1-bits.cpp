class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto params=[&](int a,int b){
            if( __builtin_popcount(a)==__builtin_popcount(b)) return a<b;
            return __builtin_popcount(a)<__builtin_popcount(b);
        };
        sort(arr.begin(),arr.end(),params);
        return arr;
    }
};