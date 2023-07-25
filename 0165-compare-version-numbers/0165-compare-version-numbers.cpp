class Solution {
public:
    
    int flag=1;
    
    int compareVersion(string version1, string version2) {
        
        int n=version1.length();
        
        int m=version2.length();
        
        int i=0;
        int j=0;
        
        while(i<n||j<m)
        {
            int n1=0;
            int n2=0;
            
            while(i<n&&version1[i]!='.')
            {
                n1=n1*10+(version1[i]-'0');
                i++;
            }
            
            while(j<m &&version2[j]!='.')
            {
                n2=n2*10+(version2[j]-'0');
                j++;
            }
            
            if(n1<n2) return -1;
            if(n1>n2) return 1;
            i++;
            j++;
            
        }
        return 0;
        
    }
};