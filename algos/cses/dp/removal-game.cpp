#include <bits/stdc++.h>
using namespace std;
vector<long long> pref;
long long sum(int l, int r)
{
    return pref[r] - (l ? pref[l - 1] : 0);
}

long long rec(vector<long long> &nums, int i, int j, vector<vector<long long>> &dp)
{
    if (j == i)
        return nums[i];
    else if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = max(nums[i] + sum(i + 1, j) - rec(nums, i + 1, j, dp), nums[j] + sum(i, j - 1) - rec(nums, i, j - 1, dp));
}
long long removal_game(vector<long long> &nums)
{
    int n = nums.size();
    /*
        state: max sum from hear or there
        transition -> dp[i][j][turn] =max(nums[j] - dp[i][j-1][!turn], nums[i] - dp[i-1][j][!turn]);
        base case  ->

    */
    vector<vector<long long>> dp(n + 3, vector<long long>(n + 3, -1));
    pref = vector<long long>(n);
    for (int i = 0; i < n; i++)
        pref[i] = pref[i ? i - 1 : 0] + nums[i];
    return rec(nums, 0, n - 1, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (auto &x : nums)
        cin >> x;

    cout << removal_game(nums) << "\n";
}