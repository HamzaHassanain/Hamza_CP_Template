#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;

struct SqrtDecomp
{
    vector<ll> arr;
    vector<ll> blocks;
    ll n, block_size;

    SqrtDecomp(vector<ll> &a)
    {
        arr = a;
        n = arr.size();
        block_size = sqrt(n) + 1;
        blocks.resize(block_size, 0);
        for (ll i = 0; i < n; i++)
        {
            blocks[i / block_size] += arr[i];
        }
    }

    void update(ll idx, ll val)
    {
        ll block_idx = idx / block_size;
        blocks[block_idx] += val - arr[idx];
        arr[idx] = val;
    }

    ll query(ll l, ll r)
    {
        ll bl = l / block_size, br = r / block_size;
        ll ans = 0;
        if (bl == br)
        {
            for (ll i = l; i <= r; i++)
                ans += arr[i];
        }
        else
        {
            for (ll i = l; i < (bl + 1) * block_size; i++)
                ans += arr[i];
            for (ll i = bl + 1; i < br; i++)
                ans += blocks[i];
            for (ll i = br * block_size; i <= r; i++)
                ans += arr[i];
        }

        return ans;
    }
};

int main()
{
}