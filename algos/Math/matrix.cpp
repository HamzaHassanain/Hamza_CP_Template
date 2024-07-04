const ll MOD = 1e9 + 7;
ll binpow(ll a, ll b)
{
    if (b < 0)
        return 0;

    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a)
{
    return binpow(a, MOD - 2);
}

// matrix exponentiation

struct Matrix
{
    vector<vector<ll>> mat;
    ll n, m;
    Matrix(ll n, ll m)
    {
        this->n = n;
        this->m = m;
        mat.resize(n, vector<ll>(m, 0));
    }
    Matrix(vector<vector<ll>> mat)
    {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
    }
    Matrix operator*(Matrix &other)
    {
        Matrix product(n, other.m);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < other.m; j++)
            {
                for (ll k = 0; k < m; k++)
                {
                    product.mat[i][j] += mat[i][k] * other.mat[k][j];
                    product.mat[i][j] %= MOD;
                }
            }
        }
        return product;
    }
    Matrix operator^(ll p)
    {
        Matrix res(n, m);
        for (ll i = 0; i < n; i++)
            res.mat[i][i] = 1;
        Matrix a = *this;
        while (p)
        {
            if (p & 1)
                res = res * a;
            a = a * a;
            p >>= 1;
        }
        return res;
    }

    void print()
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
                cout << mat[i][j] << " ";
            cout << dl;
        }
    }
};
