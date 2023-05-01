class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& aa) {
        int n=aa.size();
        vector<int> ans(n,-1);
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=aa[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    ans[i]=st.top();
                }
            }
            st.push(aa[i%n]);
        }
        return ans;
    }
};