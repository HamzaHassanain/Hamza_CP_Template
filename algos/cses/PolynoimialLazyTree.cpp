#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
struct LazySegmentTree
{
    int size;
    long long DEFAULT;
    vector<long long> data;
    vector<pair<long long, int>> lazy;
    void init(int n, long long DEFAULT)
    {
        size = 1;
        this->DEFAULT = DEFAULT;
        while (size < n)
            size *= 2;
        data.assign(2 * size, DEFAULT);
        lazy.resize(2 * size);
    }
    void build(vector<ll> &a, int x, int lx, int rx)
    {
        if (rx == lx)
        {
            if (lx < a.size())
                data[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x, lx, m);
        build(a, 2 * x + 1, m + 1, rx);
        data[x] = data[2 * x] + data[2 * x + 1];
    }
    void build(vector<ll> &a)
    {
        build(a, 1, 0, size - 1);
    }
    long long gauss(int start, int len, int step)
    {
        return 1ll * start * len + 1ll * step * len * (len - 1) / 2;
    }
    void workLazy(int &node, int beginSeg, int endSeg)
    {
        data[node] += gauss(lazy[node].first, endSeg - beginSeg + 1, lazy[node].second);
        int mid = (beginSeg + endSeg) / 2;
        if (beginSeg != endSeg)
        {
            lazy[2 * node].first += lazy[node].first;
            lazy[2 * node].second += lazy[node].second;
            lazy[2 * node + 1].first += lazy[node].first + lazy[node].second * (mid - beginSeg + 1);
            lazy[2 * node + 1].second += lazy[node].second;
        }

        lazy[node] = {0, 0};
    }
    void set(int left, int right, int node, int beginSeg, int endSeg, ll value)
    {
        if (lazy[node].first || lazy[node].second)
            workLazy(node, beginSeg, endSeg);

        if (beginSeg > right || left > endSeg)
            return;

        if (beginSeg >= left && endSeg <= right)
        {
            lazy[node].first = value + (beginSeg - left);
            lazy[node].second++;
            workLazy(node, beginSeg, endSeg);
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        this->set(left, right, 2 * node, beginSeg, mid, value);
        this->set(left, right, 2 * node + 1, mid + 1, endSeg, value);

        data[node] = data[2 * node] + data[2 * node + 1];
    }

    long long query(int left, int right, int node, int beginSeg, int endSeg)
    {
        workLazy(node, beginSeg, endSeg);

        if (beginSeg > right || left > endSeg)
            return DEFAULT;

        if (beginSeg >= left && endSeg <= right)
            return data[node];

        int mid = (beginSeg + endSeg) / 2;
        long long a = this->query(left, right, 2 * node, beginSeg, mid);
        long long b = this->query(left, right, 2 * node + 1, mid + 1, endSeg);

        return a + b;
    }
    long long query(int left, int right)
    {

        return query(left, right, 1, 1, size);
    }
    void set(int left, int right, long long value)
    {
        set(left, right, 1, 1, size, value);
    }
};