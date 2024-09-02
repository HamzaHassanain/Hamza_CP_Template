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

ll bst(vector<int> &arr, vector<int> &brr, ll i, int a, int b)
{
    if (i == arr.size())
        return min(a, b);

    return max(bst(arr, brr, i + 1, a + arr[i], b), bst(arr, brr, i + 1, a, b + brr[i]));
}

class Sure : public Solution
{
public:
    void solve(std::ifstream &fin, std::ofstream &fout)
    {
        ll n;
        fin >> n;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++)
            fin >> arr[i];

        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fout << bst(arr, brr, 0, 0, 0) << dl;
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
        ll n = get_random(1, 4);
        fout << n << dl;
        for (int i = 0; i < n; i++)
            fout << get_random(-1, 1) << " ";
        fout << dl;
        for (int i = 0; i < n; i++)
            fout << get_random(-1, 1) << " ";
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
        vector<vector<ll>> a(2, vector<ll>(n));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
        }

        multiset<pair<ll, ll>> alls;
        for (int i = 0; i < n; i++)
        {
            alls.insert({a[0][i], a[1][i]});
        }
        multiset<pair<ll, ll>> notEquals;
        for (int i = 0; i < n; i++)
        {
            if (a[0][i] != a[1][i])
                notEquals.insert({a[0][i], a[1][i]}), alls.erase(alls.find({a[0][i], a[1][i]}));
        }
        ll scrF = 0, scrS = 0;
        for (auto [f, s] : notEquals)
        {
            if (f == 1)
                scrF += f;
            else if (s == 1)
                scrS += s;
            else
            {
                if (f == -1)
                    scrS += s;
                else
                    scrF += f;
            }
        }

        multiset<pair<ll, ll>> negsAnsZeros;
        for (int i = 0; i < n; i++)
        {
            if (a[0][i] == a[1][i] and (a[0][i] == -1 or a[0][i] == 0))
                negsAnsZeros.insert({a[0][i], a[1][i]}), alls.erase(alls.find({a[0][i], a[1][i]}));
        }
        for (auto [f, s] : negsAnsZeros)
        {
            if (!f)
                continue;

            else
            {
                if (scrF > scrS)
                    scrF += f;
                else
                    scrS += s;
            }
        }

        for (auto [f, s] : alls)
        {

            if (scrF > scrS)
                scrS += s;
            else
                scrF += f;
        }
        fout << min(scrF, scrS) << dl;
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