
struct SparseTable
{
    vector<vector<ll>> st;
    vector<ll> log;
    ll merge(ll a, ll b)
    {
        return min(a, b);
    }
    SparseTable(vector<ll> &a)
    {
        int n = a.size();
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i / 2] + 1;
        st.assign(n, vector<ll>(log[n] + 1));
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll query(int l, int r)
    {
        int j = log[r - l + 1];
        return merge(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
