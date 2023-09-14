class Solution {
public:
    
    void fun(unordered_map<string,multiset<string>> &mp,stack<string> &st,string str,unordered_map<string,int> &vis){
        while(!mp[str].empty()){
            string val=*mp[str].begin();
            mp[str].erase(mp[str].begin());
            fun(mp,st,val,vis);
        }
        st.push(str);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        stack<string> st;
        unordered_map<string,multiset<string>> mp;
        // unordered_map<string,multiset<string>> mp;
        unordered_map<string,int> vis;
        
        for(auto x:tickets){
            mp[x[0]].insert(x[1]);
        }
        fun(mp,st,"JFK",vis);
        vector<string> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};