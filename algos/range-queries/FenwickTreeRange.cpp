struct Fenwick_Tree_Range
{
private:
    int N;
    int DEFAULT;
    vector<int> M, C;

    inline int lowest_bit(int idx)
    {
        return (idx & -idx);
    }

    inline void add_range(int idx, int addM, int addC)
    {
        idx++;
        while (idx <= N)
        {
            M[idx] += addM;
            C[idx] += addC;
            idx += lowest_bit(idx);
        }
    }

    inline void add(int idx, int val)
    {
        add(idx, idx, val);
    }

    inline int get(int idx)
    {
        int ans = DEFAULT;
        int pos = idx++;
        while (idx)
        {
            ans += pos * M[idx] + C[idx];
            idx -= lowest_bit(idx);
        }
        return ans;
    }

public:
    inline void add(int l, int r, int val)
    {
        add_range(l, val, -val * (l - 1));
        add_range(r + 1, -val, val * r);
    }
    inline int query(int L, int R)
    {
        if (L > R)
            return DEFAULT;
        return get(R) - get(L - 1);
    }

    void init(int sz = 0)
    {
        N = sz + 1, DEFAULT = 0;
        M = C = vector<int>(N + 10);
    }
    inline void build(vector<int> &nums)
    {
        for (int i = 0; i < sz(nums); i++)
            add(i, i, nums[i]);
    }
};