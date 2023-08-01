class Solution {
private:
    void fun(vector<vector<int>> &ans,int ind,int n,int k,vector<int> &v)
    {
        if(ind-1>n) {
            return ;
        }
        
        if(k==0){
            ans.push_back(v);
            return;
        }
        

        for(int i=ind;i<=n;i++)
        {
            v.push_back(i);
            fun(ans,i+1,n,k-1,v);
            v.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(k>n) return ans;
        vector<int> v;
        fun(ans,1,n,k,v);
        return ans;
    }
};