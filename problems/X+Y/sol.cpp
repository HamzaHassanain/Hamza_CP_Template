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

struct Complex
{
    ll r, i;
    Complex(ll r, ll i) : r(r), i(i) {}
    Complex() {}

    Complex operator+(const Complex &c) const
    {
        return {r + c.r, i + c.i};
    }

    ll real() const
    {
        return r;
    }

    ll imag() const
    {
        return i;
    }
};

Complex pares_img(string s)
{
    int real = 0, img = 0;
    bool neg = false;
    neg = s[0] == '-';
    string part = "";
    int i = neg;
    for (; i < s.size(); i++)
    {
        if (s[i] == '-' or s[i] == '+')
        {
            real = (neg ? -1 : 1) * stoi(part);
            neg = (s[i] == '-');
            part = "";
        }
        else if (s[i] == 'i')
        {
            if (part.size() == 0)
                part = "1";
            img = (neg ? -1 : 1) * stoi(part);
            part = "";
            break;
        }
        else
        {
            part += s[i];
        }
    }
    if (part.size())
        real = (neg ? -1 : 1) * stoi(part);

    return {real, img};
}
void test_case()
{
    /*

        10-10i -1+9i
    */
    string s1, s2;
    cin >> s1 >> s2;
    Complex a = pares_img(s1);
    Complex b = pares_img(s2);
    // cout << s1 << " " << s2 << dl;

    auto c = a + b;

    if (c.real())
        cout << c.real();
    if (c.imag())
    {
        if (c.imag() > 0 and c.real() != 0)
            cout << "+";

        if (c.imag() == -1)
            cout << "-i";
        else if (c.imag() == 1)
            cout << "i";
        else
            cout << c.imag() << "i";
    }

    if (c.real() == 0 and c.imag() == 0)
        cout << 0;
    cout << dl;
}
int main()
{

    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);

    int tc = 1;

    cin >> tc;

    while (tc--)
        test_case();
}