#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;

    /*
        DP with BS where dp[i] is the last element of the sequnece of length i
    */
    vector<int> dp(n + 1, 1e9 + 7);
    dp[0] = -1e9 - 7;
    int bst = 1;
    for (int i = 0; i < n; i++)
    {
        int len = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (dp[len - 1] < nums[i] and nums[i] < dp[len])
            dp[len] = nums[i], bst = max(len, bst);
    }
    cout << bst << "\n";
}
