#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 1;
#define sz(x) (int)x.size()
struct SegmentTree
{
    int size;
    int DEFAULT;
    vector<long long> tree;
    vector<int> v;

    function<long long(long long, long long)> merge;

    SegmentTree(int n, int DEFAULT, vector<int> &a, function<long long(long long, long long)> &merge)
    {
        this->DEFAULT = DEFAULT;
        this->merge = merge;

        v = a;
        while (sz(v) & (sz(v) - 1))
            v.push_back(DEFAULT);

        tree.resize(sz(v) * 2, DEFAULT);
        for (int i = 0; i < sz(v); i++)
            tree[i + sz(v)] = v[i];
        for (int i = sz(v) - 1; i >= 1; i--)
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }
    SegmentTree(int n, int DEFAULT, function<long long(long long, long long)> &merge)
    {
        this->DEFAULT = DEFAULT;
        this->merge = merge;
        vector<int> a = vector<int>(n, DEFAULT);
        v = a;
        while (sz(v) & (sz(v) - 1))
            v.push_back(DEFAULT);

        tree.resize(sz(v) * 2, DEFAULT);
    }
    void update(int idx, int val)
    {
        idx--;
        idx += sz(v);
        tree[idx] = val;
        for (idx >>= 1; idx > 0; idx >>= 1)
            tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }
    long long query(int l, int r)
    {
        // l--;
        r++;
        long long res = DEFAULT;
        for (l += sz(v), r += sz(v); l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = merge(res, tree[l++]);
            if (r & 1)
                res = merge(res, tree[--r]);
        }
        return res;
    }
};
