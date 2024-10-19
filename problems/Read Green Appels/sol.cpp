#include <bits/stdc++.h>
using namespace std;
#define dl '\n'
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (ll)(x).size()

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> as(a), bs(b), cs(c);
    for (int i = 0; i < a; i++)
        cin >> as[i];
    for (int i = 0; i < b; i++)
        cin >> bs[i];
    for (int i = 0; i < c; i++)
        cin >> cs[i];

    sort(rall(as));
    sort(rall(bs));
    sort(rall(cs));

    while (as.size() > x)
        as.pop_back();
    while (bs.size() > y)
        bs.pop_back();

    map<ll, ll> a_mst, b_mst;
    for (auto i : as)
        a_mst[i]++;
    for (auto i : bs)
        b_mst[i]++;

    int i = 0;
    for (int i = 0; i < cs.size(); i++)
    {
        ll a_frnt = a_mst.begin()->first;
        ll b_frnt = b_mst.begin()->first;
        if (cs[i] >= min(a_frnt, b_frnt))
        {
            if (a_frnt < b_frnt)
            {
                a_mst[a_frnt]--;
                if (a_mst[a_frnt] == 0)
                    a_mst.erase(a_frnt);

                a_mst[cs[i]]++;
            }
            else
            {
                b_mst[b_frnt]--;
                if (b_mst[b_frnt] == 0)
                    b_mst.erase(b_frnt);

                b_mst[cs[i]]++;
            }
        }
    }
    ll ans = 0;
    for (auto i : a_mst)
        ans += i.first * i.second;

    for (auto i : b_mst)
        ans += i.first * i.second;

    cout << ans << dl;
    return 0;
}