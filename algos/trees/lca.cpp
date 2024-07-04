#include <bits/stdc++.h>
using namespace std;

struct LCA
{

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
    int N;

    LCA(vector<vector<int>> &adj)
    {
        this->adj = adj;
        N = adj.size();
        LOG = 32 - __builtin_clz(N);
        up.assign(N, vector<int>(LOG));
        depth.assign(N, 0);
    }

    void dfs(int u, int p)
    {
        up[u][0] = p;
        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u])
        {
            if (v != p)
            {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (depth[up[u][i]] >= depth[v])
            {
                u = up[u][i];
            }
        }
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v)
    {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};