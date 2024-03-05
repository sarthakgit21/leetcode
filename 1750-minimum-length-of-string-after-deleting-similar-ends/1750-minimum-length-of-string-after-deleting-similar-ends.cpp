class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        int ans=n;
        
        while(i<j){
            if(s[i]==s[j]){
                int len=0;
                char c=s[i];
                while(i<j && s[i]==c){
                    i++;
                    len++;
                }

                while(j>=i && s[j]==c){
                    j--;
                    len++;
                }
                ans-=len;
            }
            else{
                break;
            }
            
        }
        
        return ans;
    }
};