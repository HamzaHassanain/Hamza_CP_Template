#include <bits/stdc++.h>
using namespace std;

struct FenwickTree
{
    vector<int> bit; 
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

   
    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

 
    int sum(int l, int r) { return sum(r) - sum(l - 1); }

   
    void add(int idx, int x)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += x;
    }

    // set value at pos idx to x
    void set(int idx, int x) { add(idx, x - sum(idx, idx)); }
};



