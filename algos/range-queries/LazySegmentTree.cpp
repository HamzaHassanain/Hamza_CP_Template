#include <bits/stdc++.h>
using namespace std;

struct LazySegmentTree
{
    int size;
    long long DEFAULT;
    vector<long long> data, lazy;
    void init(int n, long long DEFAULT)
    {
        size = 1;
        this->DEFAULT = DEFAULT;
        while (size < n)
            size *= 2;
        data.assign(2 * size, DEFAULT);
        lazy.assign(2 * size, DEFAULT);
    }
    void workLazy(int &node, int &beginSeg, int &endSeg)
    {
        if (lazy[node] != DEFAULT)
        {
            long long dx = lazy[node];
            lazy[node] = DEFAULT;
            data[node] += dx * (endSeg - beginSeg + 1);
            if (beginSeg != endSeg)
            {
                lazy[2 * node] += dx;
                lazy[2 * node + 1] += dx;
            }
        }
    }
    void range_add(int left, int right, int node, int beginSeg, int endSeg, long long value)
    {
        workLazy(node, beginSeg, endSeg);

        if (beginSeg > right || left > endSeg)
            return;

        if (beginSeg >= left && endSeg <= right)
        {
            long long dx = value * (endSeg - beginSeg + 1);
            data[node] += dx;

            if (beginSeg != endSeg)
            {
                lazy[2 * node] += value;
                lazy[2 * node + 1] += value;
            }
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        this->range_add(left, right, 2 * node, beginSeg, mid, value);
        this->range_add(left, right, 2 * node + 1, mid + 1, endSeg, value);

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
    void range_add(int left, int right, long long value)
    {
        range_add(left, right, 1, 1, size, value);
    }
};
