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

ll mex(vector<ll> a)
{
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] != i)
            return i;
    }
    return a.size();
}
class Sure : public Solution
{
public:
    void solve(std::ifstream &fin, std::ofstream &fout)
    {
        ll n;
        fin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            fin >> x;
        ll ans = mex(a);
        for (int i = 0; i < n; i++)
        {

            for (int j = i; j < n; j++)
            {
                vector<ll> b = a;
                vector<ll> xxx;
                for (int k = i; k <= j; k++)
                    xxx.push_back(b[k]);
                ll mxFromItoJ = mex(xxx);
                for (int k = i; k <= j; k++)
                    b[k] = mxFromItoJ;

                ans = max(ans, mex(b));
            }
        }

        fout << ans << dl;
    }
};
long long get_random(long long l, long long r)
{

    return l + rand() % (r - l + 1);
}
class GEN : public Generator
{
public:
    void generate(std::ofstream &fout)
    {
        ll n = get_random(1, 10);
        fout << n << dl;
        for (ll i = 0; i < n; i++)
        {

            fout << get_random(0, n) << " ";
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
        vector<ll> a(n);
        for (ll &x : a)
            fin >> x;

        if (mex(a) == n)
        {
            fout << n << dl;
            return;
        }
        if (mex(a) == 0)
        {
            bool did = false;
            vector<bool> vis(n + 1);
            for (int i = 0; i < n; i++)
            {
                if (vis[a[i]])
                {
                    a[i] = 0;
                    did = true;
                    break;
                }
                vis[a[i]] = true;
            }
            if (did)
                fout << mex(a) << dl;
            else
            {
                sort(all(a));
                a[n - 1] = 0;
                fout << mex(a) << dl;
            }
            return;
        }

        vector<ll> subarr(n + 1);
        vector<ll> arr(n + 1);
        set<int> inSubarr, inArr, outSubarr, outArr;
        for (auto &x : a)
        {
            inArr.insert(x);
            arr[x]++;
        }
        for (int i = 0; i <= n; i++)
        {
            outSubarr.insert(i);
            if (arr[i] == 0)
                outArr.insert(i);
        }
        ll arrMex = *outArr.begin();
        int ans = arrMex;
        int i = 0, j = 0;
        while (i < n)
        {
            while (j < n and *outSubarr.begin() != arrMex)
            {
                inSubarr.insert(a[j]);
                subarr[a[j]]++;
                outSubarr.erase(a[j]);

                arr[a[j]]--;
                if (arr[a[j]] == 0)
                    outArr.insert(a[j]), inArr.erase(a[j]);
                j++;
            }
            outArr.erase(arrMex);
            inArr.insert(arrMex);
            ans = max(ans, *outArr.begin());
            outArr.insert(arrMex);
            inArr.erase(arrMex);

            subarr[a[i]]--;
            if (subarr[a[i]] == 0)
                outSubarr.insert(a[i]), inSubarr.erase(a[i]);

            arr[a[i]]++;
            outArr.erase(a[i]), inArr.insert(a[i]);

            i++;
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

    // abf.run(100);

    // abf.cleanup();
    return 0;
}