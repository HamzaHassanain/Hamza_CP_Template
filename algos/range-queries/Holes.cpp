#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int sq, n, q;
vector<int> a, lstPos, cntJump;
inline void sqrt_work(int i)
{
    ll nxt = i + a[i];
    ll curBlock = i / sq;
    ll nxtBlock = nxt / sq;
    if (nxt > n - 1 or curBlock != nxtBlock)
    {
        lstPos[i] = i;
        cntJump[i] = 0;
    }
    else
    {
        lstPos[i] = lstPos[nxt];
        cntJump[i] = cntJump[nxt] + 1;
    }
}
void GreatShinobiOwl()
{
    cin >> n >> q;
    a = vector<int>(n);
    for (int &x : a)
        cin >> x;

    sq = sqrt(n + 0.0) + 1;

    lstPos.assign(n, -1);
    cntJump.assign(n, 0);

    for (int i = n - 1; i >= 0; i--)
        sqrt_work(i);

    while (q--)
    {
        int t;
        cin >> t;
        if (t)
        {
            int i;
            cin >> i;
            i--;
            int ansLstPos = 0, ansCntJump = 0;
            while (i < n)
            {
                ansCntJump += cntJump[i] + 1;
                ansLstPos = lstPos[i];
                i = ansLstPos + a[ansLstPos];
            }

            cout << ansLstPos + 1 << " " << ansCntJump << dl;
        }
        else
        {
            int i, x;
            cin >> i >> x;
            i--;
            a[i] = x;
            int curBlock = i / sq;
            while (i >= 0 and i / sq == curBlock)
            {
                sqrt_work(i);
                i--;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;

#ifdef TEST_CASES
    cin >> tc;
#endif

    for (int t = 1; t <= tc; t++)
    {
        GreatShinobiOwl();
    }
    return 0;
}