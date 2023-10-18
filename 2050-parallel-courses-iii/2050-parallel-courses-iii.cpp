class Solution
{
    public:
        int minimumTime(int n, vector<vector < int>> &relations, vector< int > &time)
        {
            int N = relations.size();
            int ans = 0;

            vector<int> adj[n];
            vector<int> inDegree(n, 0);
            vector<int> start=time;
            for (int i = 0; i < N; i++)
            {
                int u = relations[i][0];
                int v = relations[i][1];
                u--;
                v--;
                // cout<<u<< " "<<v<<endl;
                inDegree[v]++;
                adj[u].push_back(v);
                // adj[v].push_back(u);
            }
            // cout<<"3";

            queue<pair<int, int>> q;
            for (int i = 0; i < n; i++)
            {
                if (inDegree[i] == 0) q.push({ i,
                    time[i] });
                else start[i]=0;
            }
            int prev=0;

            while (!q.empty())
            {
                int sz = q.size();
                for (int i = 0; i < sz; i++)
                {
                    int node = q.front().first;
                    int price = q.front().second;
                    q.pop();
                    for (auto x: adj[node])
                    {
                        start[x]=max(start[x],start[node]+time[x]);
                        // for(auto x:start) cout<<x<<" ";
                        // cout<<endl;
                        inDegree[x]--;
                        if (inDegree[x] == 0)
                        {
                            q.push({ x,
                                time[x] });
                        }
                    }
                }
                
            }

            return *max_element(start.begin(),start.end());
        }
};