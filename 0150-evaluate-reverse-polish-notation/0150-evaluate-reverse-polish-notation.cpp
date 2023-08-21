class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        if(tokens.size()==1) return stoi(tokens[0]);
        for(auto x:tokens)
        {
            if(x=="*")
            {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                st.push(val1*val2);
            }
            else if(x=="+")
            {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                st.push(val1+val2);
            }
            
            else if(x=="-")
            {
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();
                st.push(val1-val2);
            }
            
            else if(x=="/")
            {
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();
                st.push(val1/val2);
            }
            else
            {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};