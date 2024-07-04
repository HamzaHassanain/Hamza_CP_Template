#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define TEST_CASES

void CP()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ab(2, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> ab[0][i];
    for (int i = 0; i < n; i++)
        cin >> ab[1][i];
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
        CP();
    }
    return 0;
}