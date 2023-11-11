class Graph
{
    public:
        int INF = 1e9;
    vector<vector < int>> adj
    {
        101,
        vector<int> (101, 1e9)
    };
    int N;
    void fyoldwarhsal()
    {
        for (int i = 0; i < N; ++i)
            adj[i][i] = 0;
        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {

                        adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    Graph(int n, vector<vector < int>> &edges)
    {
        N = n;
        for (auto x: edges)
        {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u][v] = w;
        }
        fyoldwarhsal();
    }

    void addEdge(vector<int> x)
    {
        int u = x[0];
        int v = x[1];
        int w = x[2];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][u] + adj[v][j] + w);
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        int ans = adj[node1][node2];
        return ans == 1e9 ? -1 : ans;
    }
};

/**
 *Your Graph object will be instantiated and called as such:
 *Graph* obj = new Graph(n, edges);
 *obj->addEdge(edge);
 *int param_2 = obj->shortestPath(node1,node2);
 */