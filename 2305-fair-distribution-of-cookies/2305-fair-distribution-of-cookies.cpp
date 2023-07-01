class Solution {
public:
    
    int fun(vector<int>& cookies, int k,int ind,vector<int> &bck){
        if(ind==cookies.size()){
            int ans=0;
            ans=*max_element(bck.begin(),bck.end());
                return ans;
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            bck[i]+=cookies[ind];
            ans=min(ans,fun(cookies,k,ind+1,bck));
            bck[i]-=cookies[ind];
        }
        return ans;
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=0;
        int n=cookies.size();
        vector<int> bck(n,0);
        ans=fun(cookies,k,0,bck);
        return ans;
    }
};