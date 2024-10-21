#include <bits/stdc++.h>
using namespace std;
#define dl '\n'
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (ll)(x).size()
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n + 10);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<ll>> adj(n + 10);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    queue<ll> q;
    q.push(1);
    vector<ll> lvlsSums(n + 10);
    int lvl = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int node = q.front();
            q.pop();
            lvlsSums[lvl] += v[node - 1];
            for (auto child : adj[node])
                q.push(child);
        }
        lvl++;
    }
    lvl--;
    ll lstNonZero = 0;
    for (int i = 0; i <= lvl; i++)
    {
        if (lvlsSums[i] != 0)
        {
            lstNonZero = i;
        }
    }
    ll sn = lvlsSums[lstNonZero];
    if (sn == 0)
        cout << "0\n";
    else if (sn < 0)
        cout << "-\n";
    else
        cout << "+\n";
    return 0;
}