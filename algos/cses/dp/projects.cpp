#include <bits/stdc++.h>
using namespace std;

struct Project
{
    int beg, end;
    long long res;
    Project(int beg, int end, long long res) : beg{beg}, end{end}, res{res} {}
    Project() {}
};
bool operator<(const Project &a, const Project &b)
{
    if (a.end < b.end)
        return 1;
    return 0;
}

int bs(vector<Project> &projects, int end, Project &cur)
{
    int low = 1;
    int hi = end;
    int res = 0;
    while (low <= hi)
    {
        int mid = (low + hi) / 2;
        if (cur.beg > projects[mid].end)
        {
            res = mid;
            low = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<Project> projects(n);

    for (auto &p : projects)
        cin >> p.beg >> p.end >> p.res;

    projects.push_back({0, 0, 0});
    sort(projects.begin(), projects.end());

    vector<long long> dp(n + 1, 0);

    long long mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int next = bs(projects, i, projects[i]);
        dp[i] = max(dp[i - 1], projects[i].res + dp[next]);
        mx = max(dp[i], mx);
    }

    cout << mx << "\n";
}
