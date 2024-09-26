#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rv(exp) return void(cout << exp << dl)
template <typename T>
ostream &operator<<(ostream &out, vector<T> &vec)
{
    for (auto &x : vec)
        out << x << " ";
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &vec)
{
    for (auto &x : vec)
        in >> x;
    return in;
}

void solve()
{
    
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc = 1;

    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}