#include <bits/stdc++.h>
using namespace std;

const string dl = "\n";
const long long OO = 1e9;
const long long MOD = 1e9 + 7;
#define ll long long
#define ull long long
#define mod(a, b) (a % b + b) % b
#define of :
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rv(exp) return void(cout << exp << dl)
void dfs(vector<string> &grid, int w, int i, int j)
{
    if (i >= grid.size() or j >= grid.size() or i < 0 or j < 0)
        return;
    if (grid[i][j] == '#')
        return;
    if (grid[i][j] == 'V')
        return;

    grid[i][j] = 'V';

    for (int d = -w; d <= w; d++)
    {
        for (int k = -w; k <= w; k++)
        {
            dfs(grid, w, i + d, j + k);
        }
    }
}
void test_case()
{

    int n, w;
    cin >> n >> w;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 'P')
            {
                dfs(grid, w, i, j);
                goto ans;
            }

ans:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 'V')
                grid[i][j] = 'P';
    }

    for (int i = 0; i < n; i++)
        cout << grid[i] << dl;
}
int main()
{

    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);

    int tc = 1;

    while (tc--)
        test_case();
}