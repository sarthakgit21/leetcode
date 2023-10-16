class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0) return {1};
        if(n==1) return {1,1};
        
        vector<int> vals={1,1};
        vector<int> ans;
        for(int i=3;i<=n+1;i++){
            ans.resize(i);
            ans[0]=ans[i-1]=1;
            for(int j=1;j<i-1;j++){
                // cout<<j<<" "<<i<<endl;
                ans[j]=vals[j-1]+vals[j];
            }
            vals=ans;
        }
        
        return ans;
            
        
    }
};