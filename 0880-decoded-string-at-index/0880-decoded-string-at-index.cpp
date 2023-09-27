class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz=0;
        for(auto x:s){
            if(isdigit(x)){
                sz=sz*(x-'0');
            }
            else{
                sz++;
            }
        }
        
        for(int i=s.size()-1;i>=0;i--){
            k=k%sz;
            if(k==0&&isalpha(s[i])){
                return (string)""+s[i];
            }
            if(isdigit(s[i])){
                sz/=(s[i]-'0');
            }
            else{
                sz--;
            }
        }
        
        return "";
    }
};