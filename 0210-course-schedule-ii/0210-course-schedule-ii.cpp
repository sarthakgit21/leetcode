class Solution {
public:
    bool hasCycle=false;
    
    void DFS(vector<bool>&vis,vector<bool>&inRec,int node,stack<int> &st,unordered_map<int,vector<int>> &mp)
    {
        vis[node]=1;
        inRec[node]=1;
        
        for(auto x:mp[node])
        {
            if(inRec[x])
            {
                hasCycle=true;
                return;
            }
            
            if(!vis[x])
            {
                DFS(vis,inRec,x,st,mp);
            }
            
        }
        st.push(node);
        inRec[node]=0;
        
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> inRec(numCourses,false);
        vector<bool> vis(numCourses,false);
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0];    
            
            int b=prerequisites[i][1];
            
            mp[b].push_back(a);
            
            
        }
        
        stack<int> st;
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                DFS(vis,inRec,i,st,mp);
            }
        }
        
        
        if(hasCycle) return {};
        vector<int> ans;
        while(!st.empty()) ans.push_back(st.top()),st.pop();
        return ans;
        
    }
};