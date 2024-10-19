#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;

struct BinaryTrie
{

    struct Node
    {
        Node *child[2];
        ll cnt = 0;
        Node()
        {
            child[0] = child[1] = nullptr;
        }
    };

    Node *root = new Node();

    void insert(ll x)
    {
        Node *cur = root;
        for (ll i = 60; i >= 0; i--)
        {
            bool b = (1ll << i) & x;
            if (cur->child[b] == nullptr)
            {
                cur->child[b] = new Node();
            }
            cur = cur->child[b];
            cur->cnt++;
        }
    }

    void erase(ll x)
    {
        Node *cur = root;
        for (ll i = 60; i >= 0; i--)
        {
            bool b = (1ll << i) & x;
            cur = cur->child[b];
            cur->cnt--;
        }
    }
    ll maxXor(ll x)
    {
        Node *cur = root;
        ll ans = 0;
        for (ll i = 60; i >= 0; i--)
        {
            bool b = (1ll << i) & x;
            if (cur->child[b ^ 1] != nullptr)
            {
                ans |= (1ll << i);
                cur = cur->child[b ^ 1];
            }
            else
            {
                cur = cur->child[b];
            }
        }
        return ans;
    }
    ll minXor(ll x)
    {
        Node *cur = root;
        ll ans = 0;
        for (ll i = 60; i >= 0; i--)
        {
            bool b = (1ll << i) & x;
            if (cur->child[b] != nullptr)
            {
                cur = cur->child[b];
            }
            else
            {
                ans |= (1ll << i);
                cur = cur->child[b ^ 1];
            }
        }
        return ans;
    }
    ll cntXorLessThanK(ll x, ll k)
    {
        Node *cur = root;
        ll ans = 0;
        for (ll i = 60; i >= 0; i--)
        {
            if (cur == nullptr)
                break;
            bool b = (1ll << i) & x;
            bool kb = (1ll << i) & k;
            if (kb)
            {
                if (cur->child[b] != nullptr)
                {
                    ans += cur->child[b]->cnt;
                }
                cur = cur->child[1 - b];
            }
            else
            {
                cur = cur->child[b];
            }
        }
        if (cur)
            ans += cur->cnt;
        return ans;
    }
    ll cntGreaterThanK(ll x, ll k)
    {
        Node *cur = root;
        ll ans = 0;
        ll curXor = 0;

        for (ll i = 60; i >= 0; i--)
        {
            if (not cur)
                break;
            bool b = (1ll << i) & x;
            if ((curXor | (1ll << i)) >= k)
            {
                ans += cur->child[b ^ 1] ? cur->child[b ^ 1]->cnt : 0;
                cur = cur->child[b];
            }
            else
            {
                cur = cur->child[b ^ 1];
                curXor |= (1ll << i);
            }
        }

        if (curXor >= k)
            ans += cur->cnt;

        return ans;
    }
};

int SQ;
struct MO_Query
{
    int l, r, q_idx, block_idx;
    MO_Query() {}
    MO_Query(int _l, int _r, int _q_idx)
    {
        l = _l, r = _r, q_idx = _q_idx, block_idx = _l / SQ;
    }
    bool operator<(const MO_Query &y) const
    {
        if (block_idx != y.block_idx)
        {
            return block_idx < y.block_idx;
        }
        return r < y.r;
    }
};
struct MOs
{
    long long k, n, q;
    vector<long long> arr, q_ans;
    long long res = 0;
    vector<MO_Query> queries;
    vector<ll> i_ans;
    BinaryTrie trie;
    MOs() {}
    MOs(long long _n, long long _k, long long _q, vector<long long> &_arr, vector<MO_Query> &_queries)
    {
        n = _n;
        k = _k;
        q = _q;
        arr = _arr;          // arr is one based
        i_ans.resize(n + 1); // i_ans is one based
        queries = _queries;  // queries are zero based
        q_ans.resize(q);
    }
    void buildAnswer()
    {

        sort(queries.begin(), queries.end());

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

            q_ans[queries[i].q_idx] = res;
        }
    };
    void printAnswer()
    {
        for (int i = 0; i < q; i++)
        {
            cout << q_ans[i] << ' ';
        }
        cout << '\n';
    }
    void add(int idx)
    {
        trie.cntXorLessThanK(arr[idx], k);
        res += trie.cntXorLessThanK(arr[idx], k);
        trie.insert(arr[idx]);
        // cout << idx << " " << i_ans[idx] << " " << res << dl;
    }
    void remove(int idx)
    {
        trie.erase(arr[idx]);
        res -= trie.cntXorLessThanK(arr[idx], k);
    }
};

void zolve()
{
    ll n, q, k;
    cin >> n >> k >> q;
    SQ = sqrt(n) + 1;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<MO_Query> queries;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back(MO_Query(l, r, i));
    }
    MOs mo(n, k, q, arr, queries);
    mo.buildAnswer();
    mo.printAnswer();
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc = 1;

    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        zolve();
    }
    return 0;
}