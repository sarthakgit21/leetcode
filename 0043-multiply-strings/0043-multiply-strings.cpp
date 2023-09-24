class Solution {
public:
    
    int to_int(string s){
        int n=s.size();
        int val=0;
        
        for(int i=n-1;i>=0;i--){
            val=val*10 + (s[i]-'0');
        }
        
        return val;
    }
    
    string to_str(int n){
        
        string ans="";
        if(n==0) return "0";
        while(n>0){
            int rem=n%10;
            ans+=(rem+'0');
            n=n/10;
        }
        rev(ans);
        return ans;
        
    }
    string rev(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            int temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        
        return s;
    }
    string multiply(string num1, string num2) {
                
        int n=num1.size();
        int m=num2.size();
        rev(num1);
        rev(num2);
        // cout<<n+m;
        if(num1=="0") return "0";
        if(num2=="0") return "0";
        vector<int> v(n+m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=(num1[i]-'0')*(num2[j]-'0');
                // if(val==0) return "0";
                v[i+j] +=val;
                v[i+j+1] +=(v[i+j]/10);
                v[i+j] %=10;
                // cout<<v[i+j];
            }
        }
        reverse(v.begin(),v.end());
        // for(auto x:v) cout<<x;
        // cout<<endl;
        int i=0;
        while(i<(n+m)&&v[i]==0){
            i++;
        }
        // cout<<i;
        string ans="";
        while(i<(n+m)){
            ans+=(v[i]+'0');
            i++;
            // cout<<v[i];
        }
        return ans;
        
    }
};