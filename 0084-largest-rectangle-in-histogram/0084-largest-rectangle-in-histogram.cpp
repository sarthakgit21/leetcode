class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int h=heights[st.top()];
                st.pop();
                int val;
                if(st.empty()) val=i;
                else val=i-(st.top())-1;
                ans=max(ans,val*h);
            }
            st.push(i);
        }
        return ans;
    }
};