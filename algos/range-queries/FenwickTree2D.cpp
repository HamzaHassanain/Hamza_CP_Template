#define sz(x) (int)x.size()
struct Fenwick_Tree_2D
{

    // Time Complexity: O(log(n) * log(m)) for both query and update

    vector<vector<ll>> Tree;
    int n, m;
    ll DEFAULT;

    Fenwick_Tree_2D(int rows = 0, int cols = 0)
    {
        n = rows + 1, m = cols + 1, DEFAULT = 0;
        Tree.assign(n + 10, vector<ll>(m + 10, DEFAULT));
    }

    int lowest_bit(int idx)
    {
        return (idx & -idx);
    }

    void build(vector<vector<ll>> &nums)
    {
        for (int i = 0; i < sz(nums); i++)
            for (int j = 0; j < sz(nums[0]); j++)
                add(i + 1, j + 1, nums[i][j]);
    }

    ll operation(ll a, ll b)
    {
        return a + b;
    }

    void add(int idx, int jdx, ll val)
    {
        int i = idx + 1, j = jdx + 1;
        while (i <= n)
        {
            j = jdx + 1;
            while (j <= m)
            {
                Tree[i][j] = operation(Tree[i][j], val);
                j += lowest_bit(j);
            }
            i += lowest_bit(i);
        }
    }

    ll get_sum(int idx, int jdx)
    {
        ll sum = DEFAULT;
        int i = idx + 1, j = jdx + 1;
        while (i)
        {
            j = jdx + 1;
            while (j)
            {
                sum = operation(sum, Tree[i][j]);
                j -= lowest_bit(j);
            }
            i -= lowest_bit(i);
        }
        return sum;
    }

    // Get the sum of the number in the rectangle x1, y1, x2, y2

    ll query(int x1, int y1, int x2, int y2)
    {
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        return get_sum(x2, y2) - get_sum(x1 - 1, y2) - get_sum(x2, y1 - 1) + get_sum(x1 - 1, y1 - 1);
    }
};
