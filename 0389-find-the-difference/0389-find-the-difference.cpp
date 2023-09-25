class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        s+=t;
        for(auto x:s){
            ans^=x;
        }
        return ans;
        
    }
};