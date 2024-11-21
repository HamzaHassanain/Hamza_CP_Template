#include <bits/stdc++.h>
using namespace std;
#define dl '\n'
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (ll)(x).size()
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>
#define int long long
template <typename T = int, int Base = 1>
struct UnionFind
{

    vector<T> parent;
    vector<ll> weight;

    UnionFind(int MaxNodes)
    {
        parent = vector<T>(MaxNodes + 5);
        weight = vector<ll>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, weight[i] = 0;
    }

    T find_leader(int node)
    {
        if (parent[node] == node)
            return node;
        ll par = find_leader(parent[node]);
        weight[node] += weight[parent[node]];
        return parent[node] = par;
    }

    bool is_same_sets(int u, int v)
    {
        return find_leader(u) == find_leader(v);
    }

    bool union_sets(int u, int v, ll w)
    {
        ll par_u = find_leader(u);
        ll par_v = find_leader(v);
        if (par_u == par_v)
            return weight[v] - weight[u] == w;

        parent[par_u] = par_v;
        weight[par_u] = weight[v] - weight[u] - w;

        return true;
    }
};

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, q;
    cin >> n >> q;
    set<ll> ans;
    UnionFind<> dsu(n);
    for (ll i = 1; i <= q; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        if (dsu.union_sets(u, v, w))
            ans.insert(i);
    }
    for (auto i : ans)
        cout << i << " ";
    return 0;
}