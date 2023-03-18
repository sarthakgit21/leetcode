class Solution
{
    public:
        void fun(int ind, vector<string> &ans, int n, string ss)
        {
            if (ind == 0&&n==0)
            {
                ans.push_back(ss);
                return;
            }
            if(ind>0) fun(ind-1,ans,n,ss+"(");
            if(ind<n) fun(ind,ans,n-1,ss+")");
            

        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string ss;
        if (n == 0) return ans;
        fun(n, ans, n,"");
        return ans;
    }
};