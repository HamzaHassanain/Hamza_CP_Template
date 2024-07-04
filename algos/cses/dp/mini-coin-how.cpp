#include <bits/stdc++.h>
using namespace std;
vector<int> coins;
int needed, n;
void mini_coins_how()
{
    struct Use
    {
        int sum;
        vector<int> how;
        Use()
        {
            sum = 1e9, how = vector<int>(n, 0);
        }
    };
    /*
        what is my state? your state is mimumum number of coins needed to make sum
        from coins you can make -> x,x+x,x+x+x,x+y you can takeit multipul times
    */
    vector<Use> dp(needed + 10);
    dp[0].sum = 0;
    for (int x = 1; x <= needed; x++)
    {
        for (int i = 0; i < n; i++)
        {
            if (coins[i] > x)
                continue;

            if (1 + dp[x - coins[i]].sum < dp[x].sum)
            {
                dp[x].how = dp[x - coins[i]].how;
                dp[x].how[i]++;
            }
            dp[x].sum = min(dp[x].sum, 1 + dp[x - coins[i]].sum);
        }
    }
    if (dp[needed].sum >= 1e9)
    {
        cout << -1 << endl;
        return;
    }
    cout << dp[needed].sum << endl;
    for (int i = 0; i < dp[needed].how.size(); i++)
    {
        while (dp[needed].how[i]--)
            cout << coins[i] << " ";
    }
    cout << endl;
}

int main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        cin >> n >> needed;
        coins = vector<int>(n);
        for (auto &c : coins)
            cin >> c;

        mini_coins_how();
    }
}

/*
3
3 11
1 5 7
10 200
2 3 4 8 9 11 14 16 17 19
2 10
3 6



*/