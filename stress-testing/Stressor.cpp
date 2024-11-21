#include <bits/stdc++.h>
using namespace std;
#include "Stressor.h"
#include "Generator.h"
#include "Solution.h"
#define dl '\n'
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

class Sure : public Solution
{
public:
    void solve(std::ifstream &fin, std::ofstream &fout)
    {
        ll n;
        fin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            fin >> arr[i];

        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            ll mn = arr[i];
            ll mx = arr[i];
            for (ll j = i; j < n; j++)
            {
                mn = min(mn, arr[j]);
                mx = max(mx, arr[j]);
                ans += mn * mx;
                if (i < j)
                {
                    ans += mn * mx;
                }
            }
        }

        fout << ans << dl;
    }
};
int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 mt_rand(seed);
ll get_random(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(mt_rand);
}
class GEN : public Generator
{
public:
    void generate(std::ofstream &fout)
    {
        ll n = get_random(1, 10);
        fout << n << dl;

        set<ll> usd;

        for (int i = 0; i < n; i++)
        {
            ll x = get_random(1, 10);
            while (usd.count(x))
                x = get_random(1, 10);
            usd.insert(x);
            fout << x << ' ';
        }

        fout << dl;
    }
};

class Unsure : public Solution
{
public:
    void solve(std::ifstream &fin, std::ofstream &fout)
    {
        ll n;
        fin >> n;

        vector<ll> arr(n);

        for (int i = 0; i < n; i++)
            fin >> arr[i];

        ll sum = accumulate(all(arr), 0LL);

        ll ans = 0;
        for (auto &x : arr)
        {
            // ans += x * x;
        }
        for (auto &x : arr)
        {
            ans += x * (sum);
        }

        fout << ans << dl;
    }
};
class LAZY : public Stressor
{

    GEN gen;
    Sure sure;
    Unsure unsure;

public:
    void generate_test(ofstream &fout)
    {
        gen.generate(fout);
    }

    void unsure_solution(ifstream &fin, ofstream &fout)
    {
        unsure.solve(fin, fout);
    }

    void sure_solution(ifstream &fin, ofstream &fout)
    {
        sure.solve(fin, fout);
    }
};

int main()
{

    LAZY abf;

    abf.run(100);
    abf.cleanup();

    return 0;
}