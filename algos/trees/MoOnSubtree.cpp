#include <bits/stdc++.h>

#define sz(x) (int)x.size()
using namespace std;

const int N = 2e5 + 5;
const int Q = 1e5 + 5;
const int SQ = sqrt(N) + 1;

struct query
{
    int l, r, q_idx, block_idx;
    int k;
    query() {}
    query(int _l, int _r, int __k, int _q_idx)
    {
        k = __k;
        l = _l - 1, r = _r - 1, q_idx = _q_idx, block_idx = _l / SQ;
    }
    bool operator<(const query &y) const
    {
        if (block_idx != y.block_idx)
        {
            return block_idx < y.block_idx;
        }
        if (block_idx & 1)
        {
            return r < y.r;
        }
        return r > y.r;
    }
};

vector<vector<int>> adj;
vector<int> euler, tin, tout;
int timer = 0;

void dfs(int v, int p)
{
    tin[v] = timer++;
    euler.push_back(v);
    for (auto to : adj[v])
    {
        if (to != p)
        {
            dfs(to, v);
        }
    }
    tout[v] = timer++;
    euler.push_back(v);
}

int n, q, col[N + 1], res = 0, q_ans[Q], nodeFreq[N], colFreq[N], FreqOfFreq[N];
long long blks[N];
int sq;

inline int getBlock(int idx)
{
    return idx / sq;
}

void do_update(int idx, int val)
{
    blks[getBlock(idx)] += val;
}
long long get_ans(int l, int r)
{
    long long ans = 0;
    int l_block = getBlock(l);
    int r_block = getBlock(r);

    if (l_block == r_block)
    {
        for (int i = l; i <= r; i++)
        {
            ans += FreqOfFreq[i];
        }
        return ans;
    }
    else
    {
        for (int i = l; i < (l_block + 1) * sq; i++)
        {
            ans += FreqOfFreq[i];
        }
        for (int i = l_block + 1; i < r_block; i++)
        {
            ans += blks[i];
        }
        for (int i = r_block * sq; i <= r; i++)
        {
            ans += FreqOfFreq[i];
        }
        return ans;
    }
}

query queries[Q];
void add(int idx)
{
    idx++;

    int u = euler[idx];
    int c = col[u];

    nodeFreq[u]++;
    if (nodeFreq[u] == 2)
    {
        colFreq[c]++;
        FreqOfFreq[colFreq[c]]++;
        FreqOfFreq[colFreq[c] - 1]--;
        FreqOfFreq[colFreq[c] - 1] = max(0, FreqOfFreq[colFreq[c] - 1]);

        do_update(colFreq[c], 1);
        do_update(colFreq[c] - 1, -1);
    }
}
void remove(int idx)
{
    idx++;

    int u = euler[idx];
    int c = col[u];

    nodeFreq[u]--;
    if (nodeFreq[u] == 1)
    {
        colFreq[c]--;
        FreqOfFreq[colFreq[c]]++;
        FreqOfFreq[colFreq[c] + 1]--;
        FreqOfFreq[colFreq[c] + 1] = max(0, FreqOfFreq[colFreq[c] + 1]);

        do_update(colFreq[c], 1);
        do_update(colFreq[c] + 1, -1);
    }
}
void MO_process()
{
    sort(queries, queries + q);

    int l = queries[0].l, r = queries[0].l - 1;
    for (int i = 0; i < q; i++)
    {
        while (r < queries[i].r)
            add(++r);
        while (r > queries[i].r)
            remove(r--);
        while (l < queries[i].l)
            remove(l++);
        while (l > queries[i].l)
            add(--l);

        int k = queries[i].k;
        if (k > n)
        {
            q_ans[queries[i].q_idx] = 0;
            continue;
        }
        q_ans[queries[i].q_idx] = get_ans(k, n);
    }
}

signed main()
{
    int tc;
    tc = 1;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (tc--)
    {

        cin >> n >> q;
        sq = sqrt(n) + 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> col[i];
        }
        timer = 1;
        euler.push_back(0);
        adj.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            // u--, v--; // 0 based
            adj[u].push_back(v);
            adj[v].push_back(u);

            // cout << u << ' ' << v << '\n';
        }
        dfs(1, 0);

        for (int i = 0; i < q; i++)
        {

            int u, k;
            cin >> u >> k;
            int l = tin[u], r = tout[u];

            queries[i] = query(l, r, k, i);
        }
        MO_process();
        for (int i = 0; i < q; i++)
        {
            cout << q_ans[i] << '\n';
        }
    }
}