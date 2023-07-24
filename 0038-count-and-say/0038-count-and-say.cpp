class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1) return "1";
        
        if(n==2) return "11";
        
        string ans="11";
        
        for(int i=3;i<=n;i++)
        {
            
            string t="";
            
            ans+="&";
            
            int c=1;
            
            for(int j=1;j<ans.length();j++)
            {
                
                if(ans[j-1]!=ans[j])
                {
                    t+=to_string(c);
                    t+=ans[j-1];
                    c=1;
                    
                }
                else
                {
                    c++;
                }
                
            }
            
            ans=t;
            
            
        }
        
        
        return ans;
        
    }
};