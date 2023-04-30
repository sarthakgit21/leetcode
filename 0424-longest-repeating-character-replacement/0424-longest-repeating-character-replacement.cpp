class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        vector<int> chk(26,0);
        for(j=0;j<n;j++){
            chk[s[j]-'A']++;
            while(((j-i+1)-(*max_element(chk.begin(),chk.end())))>k){
                chk[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};