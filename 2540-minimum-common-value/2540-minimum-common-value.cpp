class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        
        int i=0;
        int j=0;
        
        while(i<n&&j<m){
            if(a[i]==b[j]) return b[j];
            if(a[i]<b[j]){
                i++;
            }
            else{
                j++;
            }
            // if(a[i]==b[j]) return b[i];
        }
        
        return -1;
    }
};