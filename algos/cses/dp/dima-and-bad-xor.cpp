#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
int memo[1024][500];
int constructed[1024][500];
int dp(int cur, int i)
{

    if (i == n)
        return cur;

    if (memo[cur][i] != -1)
        return memo[cur][i];

    int res = 0;
    for (int j = 0; j < m; j++)
    {
        int ans = dp(cur xor g[i][j], i + 1);
        if (ans)
        {
            constructed[ans][i] = j + 1;
            res = ans;
        }
    }
    return memo[cur][i] = res;
}
void dima_and_bad_xor(vector<vector<int>> &grid)
{
    g = grid;
    n = g.size();
    m = g[0].size();
    memset(memo, -1, sizeof(memo));
    memset(constructed, -1, sizeof(constructed));

    int ans = dp(0, 0);
    if (!ans)
    {
        cout << "NIE\n";
        return;
    }
    cout << "TAK\n";
    for (int i = 0; i < n; i++)
    {

        cout << constructed[ans][i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (auto &v : g)
    {
        for (auto &x : v)
            cin >> x;
    }
    // dp sol
    // the gready one is better fuck dp

    dima_and_bad_xor(g);
}