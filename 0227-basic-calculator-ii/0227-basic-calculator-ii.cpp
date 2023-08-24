class Solution {
public:
    int calculate(string s) {
        int curnum=0;
        char lastchar='+';
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i]))
            {
                curnum=curnum*10+int(s[i]-'0');
            }
            if(!isdigit(s[i])&&s[i]!=' '||i==s.length()-1)
            {
                if(lastchar=='+')
                {
                    st.push(curnum);
                }
                else if(lastchar=='-')
                {
                    st.push(-curnum);
                }
                else{
                    int num=0;
                    if(lastchar=='*')
                    {
                        num=st.top()*curnum;
                    }
                    else {
                        num=st.top()/curnum;
                    }
                    
                    st.pop();
                    st.push(num);
                    
                }
                lastchar=s[i];
                curnum=0;
                // cout<<st.size()<<" "<<st.top()<<endl;
            }

        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
        
        
    }
};