vector<vector<int>> adjList;
ll n, m;
ll max_biapartite_matching()
{
    vector<int> matchR(m, -1);
    vector<bool> vis;
    function<bool(int)> dfs = [&](int u)
    {
        if (vis[u])
            return false;
        vis[u] = true;
        for (int v : adjList[u])
        {
            if (matchR[v] == -1 || dfs(matchR[v]))
            {
                matchR[v] = u;
                return true;
            }
        }
        return false;
    };
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        vis.assign(m, false);
        ans += dfs(i);
    }
    return ans;
}