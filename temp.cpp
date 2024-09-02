// LUOGU_RID: 127366597
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n, q, m, r, k;
int a[100005], siz[100005], dep[100005], fa[100005], dfn[100005], tp[100005], son[100005], dfnn = 0;
vector<int> p[100005];
int f[100005][305], num[100005];
struct BIT
{
    int c[100005];
    int lowbit(int x) { return x & (-x); }
    void xg(int i, int val)
    {
        for (; i <= n; i += lowbit(i))
            c[i] += val;
    }
    int query(int i)
    {
        int res = 0;
        for (; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
} t;
void dfs1(int x, int ff)
{
    siz[x] = 1;
    fa[x] = ff;
    dep[x] = dep[ff] + 1;
    for (int j = 0; j < p[x].size(); j++)
    {
        int to = p[x][j];
        if (to == ff)
            continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if (siz[to] > siz[son[x]])
            son[x] = to;
    }
}
void dfs2(int x, int top)
{
    tp[x] = top;
    dfn[x] = ++dfnn;
    if (son[x])
        dfs2(son[x], top);
    for (int j = 0; j < p[x].size(); j++)
    {
        int to = p[x][j];
        if (to == son[x] || to == fa[x])
            continue;
        dfs2(to, to);
    }
}
/*
qh is the function to query the sum of the path from x to y


*/
int qh(int x, int y)
{

    int res = 0;
    while (tp[x] != tp[y])
    {
        if (dep[tp[x]] < dep[tp[y]])
            swap(x, y);
        res = res + t.query(dfn[tp[x]], dfn[x]);
        x = fa[tp[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res = res + t.query(dfn[x], dfn[y]);
    return res;
}
int main()
{
    // freopen("CF1111E.in","r",stdin);
    // freopen("CF1111E.out","w",stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
    {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        p[n1].push_back(n2);
        p[n2].push_back(n1);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while (q--)
    {
        scanf("%d%d%d", &k, &m, &r);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &a[i]);
            t.xg(dfn[a[i]], 1);
        }
        for (int i = 1; i <= k; i++)
            num[a[i]] = qh(a[i], r) - 1;
        auto cmp = [&](int n1, int n2)
        {
            return num[n1] < num[n2];
        };
        sort(a + 1, a + 1 + k, cmp);
        f[1][1] = 1;
        for (int i = 2; i <= k; i++)
        {
            for (int j = 1; j <= min(i, m); j++)
            {
                if (j - num[a[i]] >= 0)
                {
                    f[i][j] = (f[i - 1][j - 1] + 1ll * f[i - 1][j] * (j - num[a[i]])) % mod;
                }
                else
                    f[i][j] = f[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans = (ans + f[k][i]) % mod;
        printf("%d\n", ans);
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= min(i, m); j++)
            {
                f[i][j] = 0;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            t.xg(dfn[a[i]], -1);
        }
    }
    return 0;
}

/*
This gives a Memory Limit Exceeded (MLE).

Well, I can think of some ways to optimize this.

First, replace the Segment tree with a Binary Indexed Tree.
Remove long long where possible.

Why use a Binary Indexed Tree?
Because it uses less memory than a Segment Tree.
A segment tree uses 4 times the memory of a Binary Indexed Tree.
*/