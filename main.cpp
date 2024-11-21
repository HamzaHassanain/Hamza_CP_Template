#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 1e3;
const int M = 1e3;

int dp[N][M];
int testcase[N][M];
int curTestCase = 1;
/*
    Memoization
*/

// if (dp[i][j] != -1)
//     return dp[i][j];

if (testcase[i][j] == curTestCase)
{
    return dp[i][j];
    // dp[i][j] = 0;
}

testcase[i][j] = curTestCase;
void solve()
{
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc = 1;

    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}