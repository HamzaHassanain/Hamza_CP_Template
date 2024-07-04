#include <bits/stdc++.h>
using namespace std;
 
void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
 
int main()
{
 
    int n, x;
    cin >> n >> x;
    int nums[n];
    vector<int> dp(x + 1);
		
    for (int i = 0; i < n; i++)
        cin >> nums[i];
 
    int mod = 1e9 + 7;
    dp[0] = 1;
    for (int cur = 0; cur <= x; cur++)
    {
        for (int &num : nums)
        {
            if (num > cur)
                continue;
            dp[cur] = (dp[cur] + dp[cur - num]) % mod;
        }
    }
 
    cout << dp[x];
}
