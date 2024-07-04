#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int sum = (n + 1) * n / 2;
    if (sum % 2)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<long long>> ways(n + 1, vector<long long>(sum + 1, 0));
    ways[0][0] = 1;
    for (int cur = 0; cur <= sum / 2; cur++)
    {
        for (int x = 1; x < n; x++)
        {
            ways[x][cur] = ways[x - 1][cur];
            if (x > cur)
                continue;
            ways[x][cur] = ways[x - 1][cur - x] + ways[x - 1][cur];
            ways[x][cur] %= int(1e9 + 7);
        }
    }
    cout << ways[n - 1][sum / 2] << "\n";
}
