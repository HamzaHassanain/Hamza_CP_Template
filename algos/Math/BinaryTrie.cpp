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

    Node *root;

    BinaryTrie()
    {
        root = new Node();
    }

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
            if (cur->child[!b] != nullptr && cur->child[!b]->cnt > 0)
            {
                ans |= (1ll << i);
                cur = cur->child[!b];
            }
            else
            {
                cur = cur->child[b];
            }
        }
        return ans;
    }
};