
#include <bits/stdc++.h>

using namespace std;

signed main()
{

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> cnt(2 * n + 100);

    long long up = 0, down = 0;

    cnt[n + 0]++;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            up++;
        }
        else if (a[i] < a[i - 1])
        {
            down++;
        }
        cnt[n + (down - up)]++;
    }

    up = 0, down = 0;
    long long ans = n;

    cnt[n + 0]--;
    ans += cnt[n + 0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            up++;
        }
        else if (a[i] < a[i - 1])
        {
            down++;
        }
        cnt[n + (down - up)]--;
        ans += cnt[n + (down - up)];
    }

    cout << ans << "\n";
}