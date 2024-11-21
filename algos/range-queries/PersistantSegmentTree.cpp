#define ll long long
struct PST
{

    struct Node
    {

        ll pref, suff, sum, mx;
        Node *left, *right;

        Node(ll _val = -1e6 - 10)
        {

            pref = suff = sum = mx = _val;

            pref = max(pref, sum), suff = max(suff, sum);

            left = right = this;
        }
        Node(Node *node)
        {
            pref = node->pref;
            suff = node->suff;
            sum = node->sum;
            mx = node->mx;
            left = right = this;
        }
        Node(Node *L, Node *R)
        {
            sum = L->sum + R->sum;
            pref = max(L->pref, L->sum + R->pref);
            suff = max(R->suff, R->sum + L->suff);
            mx = max({pref, suff, L->mx, R->mx, L->suff + R->pref});
        }
        Node(Node *node, Node *l, Node *r)
        {

            pref = node->pref;
            suff = node->suff;
            sum = node->sum;
            mx = node->mx;

            left = l;
            right = r;
        }
    };

    Node *roots[100005]; // MAX Number of versions
    ll N, Lx, Rx;

    PST(int n = 0, ll lx = -1e9, ll rx = 1e9) : N(n), Lx(lx), Rx(rx)
    {
        roots[0] = new Node();
    }

    // Node *build(const vector<ll> &nums, ll l, ll r)
    // {
    //     if (l == r)
    //         return new Node(nums[l]);
    //     ll mx = l + (r - l) / 2;
    //     Node *L = build(nums, l, mx);
    //     Node *R = build(nums, mx + 1, r);
    //     return new Node(new Node(L, R), L, R);
    // }

    // void build(const vector<ll> &nums)
    // {
    //     roots[0] = build(nums, Lx, Rx);
    // }

    Node operation(Node a, Node b)
    {

        Node Merged;

        Merged.sum = a.sum + b.sum;
        Merged.pref = max(a.pref, a.sum + b.pref);
        Merged.suff = max(b.suff, b.sum + a.suff);
        Merged.mx = max({Merged.pref, Merged.suff, a.mx, b.mx, a.suff + b.pref});

        return Merged;
    }

    Node *update(Node *root, int idx, ll val, ll lx, ll rx)
    {
        if (idx < lx || idx > rx)
            return root;
        if (lx == rx)
            return new Node(val);
        ll mx = lx + (rx - lx) / 2;
        Node *L = update(root->left, idx, val, lx, mx);
        Node *R = update(root->right, idx, val, mx + 1, rx);
        return new Node(new Node(L, R), L, R);
    }

    void insert(int idx, ll val, int curr_time, int prev_time)
    {
        roots[curr_time] = update(roots[prev_time], idx, val, Lx, Rx);
    }

    void update(int idx, ll val, int curr_time)
    {
        roots[curr_time] = update(roots[curr_time], idx, val, Lx, Rx);
    }

    Node query(Node *root, int l, int r, ll lx, ll rx)
    {
        if (root == nullptr)
            return Node();
        if (lx > r || l > rx)
            return Node();
        if (lx >= l && rx <= r)
            return Node(*root);
        int mx = (lx + rx) / 2;
        Node L = query(root->left, l, r, lx, mx);
        Node R = query(root->right, l, r, mx + 1, rx);
        return operation(L, R);
    }

    ll query(int l, int r, int time)
    {
        return query(roots[time], l, r, Lx, Rx).mx;
    }
};
