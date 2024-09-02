#include <bits/stdc++.h>
using namespace std;

/*

    M(n) =
        1 if n = 1
        0 if n > 1 and n has a one or more repeated prime factors
        (-1)^k if n is a product of k distinct primes
*/
struct MobuisFunction
{
    vector<int> mu;
    MobuisFunction(int n)
    {
        mu.resize(n + 1, 0);
        mu[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                mu[j] -= mu[i];
            }
        }
    }
};

/*
Euler's phi function (which may be also called Euler's totient function) is a function that gives us the number of positive integers less or equal to a given integer n
that are coprime to n
. It is usually denoted by the greek letter ϕ
. For instance, if we consider the number 6, there are exactly 2 integers that are not greater than 6 and coprime to it. These integers are 1 and 5. Therefore ϕ(6)=2
. Similarly ϕ(9)=6
. The numbers that are not greater than 9 and coprime to it are 1, 2, 4, 5, 7 and 8. Note that according to the definition ϕ(1)=1
*/
struct PhiFunction
{
    vector<int> phi;
    PhiFunction(int n)
    {
        phi.resize(n + 1);
        iota(phi.begin(), phi.end(), 0);
        for (int i = 2; i <= n; i++)
        {
            if (phi[i] == i)
            {
                for (int j = i; j <= n; j += i)
                {
                    phi[j] -= phi[j] / i;
                }
            }
        }
    }
};
#define ll long long
struct PollardRho
{

    vector<ll> primes;
    ll N = 1e18;
    PollardRho()
    {
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        primes.push_back(7);
    }

    ll gcd(ll a, ll b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll mulmod(ll a, ll b, ll mod)
    {
        ll res = 0;
        a %= mod;
        while (b)
        {
            if (b & 1)
                res = (res + a) % mod;
            a = (a + a) % mod;
            b >>= 1;
        }
        return res;
    }

    ll power(ll a, ll b, ll mod)
    {
        ll res = 1;
        a %= mod;
        while (b)
        {
            if (b & 1)
                res = mulmod(res, a, mod);
            a = mulmod(a, a, mod);
            b >>= 1;
        }
        return res;
    }

    bool isPrime(ll n)
    {
        if (n < 2)
            return false;
        if (n < 4)
            return true;
        if (n % 2 == 0)
            return false;
        ll d = n - 1;
        while (d % 2 == 0)
            d /= 2;
        for (int i = 0; i < 5; i++)
        {
            ll a = 2 + rand() % (n - 3);
            ll x = power(a, d, n);
            if (x == 1 || x == n - 1)
                continue;
            bool prime = false;
            for (ll j = 1; j < __builtin_ctzll(n - 1); j++)
            {
                x = mulmod(x, x, n);
                if (x == n - 1)
                {
                    prime = true;
                    break;
                }
            }
            if (!prime)
                return false;
        }
        return true;
    }

    ll f(ll x, ll c)
    {
        return (mulmod(x, x, N) + c) % N;
    }

    ll rho(ll n) // returns a non-trivial factor of n
    {
        if (n % 2 == 0)
            return 2;
        ll x = 2, y = 2, d = 1, c = 1;
        while (d == 1)
        {
            x = f(x, c);
            y = f(f(y, c), c);
            d = gcd(abs(x - y), n);
        }
        return d;
    }

    vector<ll> factorize(ll n)
    {
        if (isPrime(n))
            return {n};
        ll d = rho(n);
        vector<ll> left = factorize(d);
        vector<ll> right = factorize(n / d);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

int kthAncesstor(int u, int k, vector<vector<int>> &dp) // dp is up
{
    for (int i = 0; i < dp.size(); i++)
    {
        if (k & (1 << i))
        {
            u = dp[i][u];
        }
    }
    return u;
}
