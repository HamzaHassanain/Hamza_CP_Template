#include <bits/stdc++.h>
using namespace std;

#define int long long
struct node;
node *newNode();

struct node
{
    int lv, rv, sum;
    node *left, *right;

    node() : left(NULL), right(NULL), sum(0) {}

    inline void init(int l, int r)
    {
        lv = l;
        rv = r;
    }

    inline void extend()
    {
        if (!left)
        {
            int m = (lv + rv) / 2;
            left = newNode();
            right = newNode();
            left->init(lv, m);
            right->init(m + 1, rv);
        }
    }

    int getSum(int l, int r)
    {
        if (r < lv || rv < l)
        {
            return 0;
        }

        if (l <= lv && rv <= r)
        {
            return sum;
        }

        extend();
        return left->getSum(l, r) + right->getSum(l, r);
    }

    void update(int p, int newVal)
    {
        if (lv == rv)
        {
            sum = newVal;
            return;
        }

        extend();
        (p <= left->rv ? left : right)->update(p, newVal);
        sum = left->sum + right->sum;
    }
};

node *newNode()
{
    static int bufSize = 1e7;
    static node buf[(int)1e7];
    assert(bufSize);
    return &buf[--bufSize];
}

struct DynamicSegmentTree
{

    node *root;
    DynamicSegmentTree()
    {
        root = newNode();
        root->init(0, 1e18);
    }

    void update(int p, int newVal)
    {
        root->update(p, newVal);
    }

    int getSum(int l, int r)
    {
        return root->getSum(l, r);
    }
};

signed main()
{

    DynamicSegmentTree sgt;

    sgt.update(1, 1);
    sgt.update(0, 10);

    sgt.update(1e18, 19);

    cout << sgt.getSum(0, 1e18) << endl;
    return 0;
}
