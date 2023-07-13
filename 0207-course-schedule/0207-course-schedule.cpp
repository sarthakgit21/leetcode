class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            auto it=prerequisites[i];
                adj[it[0]].push_back(it[1]);
                indegree[it[1]]++;
        }
        int count=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            count++;
            for(auto v:adj[it]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(count==numCourses) return true;
        return false;
        
    }
};