#include <bits/stdc++.h>
using namespace std;

vector<int> money_sum(vector<int> &coins)
{
    vector<bool> prev(1e5 + 10, 0);
    prev[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        vector<bool> cur(1e5 + 10, 0);
        int coin = coins[i];
        for (int x = 0; x < 1e5 + 1; x++)
        {
            if (prev[x])
                cur[x + coin] = 1, cur[coin] = 1, cur[x] = 1;
        }
        prev = cur;
    }

    vector<int> res;
    for (int i = 1; i < 1e5 + 10; i++)
    {
        if (prev[i])
            res.push_back(i);
    }
    return res;
}

int main()
{

    int n;
    cin >> n;
    vector<int> coins(n);
    for (auto &c : coins)
        cin >> c;

    auto res = money_sum(coins);
    cout << res.size() << "\n";

    for (auto &sum : res)
        cout << sum << " ";
    cout << "\n";
}
