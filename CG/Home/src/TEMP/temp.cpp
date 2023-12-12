/*
//[#]=============================================================[#]
// Author: Anonymous
// Date: 12
// Time: 2023-12-12 06:58:06
// File Name: temp.cpp
//[#]=============================================================[#]
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define a first
#define b second
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define endl "\n "
#define rep(i, a, b) for (int i = a; i < b; i++)
#define MAX_N 1000000
bool prime[MAX_N + 1];
ll fact[MAX_N + 1];

#define debuger(x)                                           \
    cout << endl;                                            \
    cout << "--------------- DEBUGER ------------" << endl;  \
    cout << (#x) << " is " << (x) << endl;                   \
    cout << "-------------------------------------" << endl; \
    cout << endl;

#define debugerarr(arr, size)            \
    do                                   \
    {                                    \
        cout << #arr << " = [";          \
        for (int i = 0; i < (size); ++i) \
        {                                \
            cout << arr[i];              \
            if (i < (size)-1)            \
                cout << ", ";            \
        }                                \
        cout << "]" << endl;             \
    } while (0)

//[#]=============================================================[#]

bool isPrime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

///[#]=============================================================[#]

int gcdExtended(int a, int b, int *x, int *y)
{

    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int b, int m)
{
    int x, y;
    int g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

//[#]=============================================================[#]

void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAX_N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= MAX_N; i += p)
                prime[i] = false;
        }
    }
}

//[#]=============================================================[#]

void factorials()
{
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++)
    {
        fact[i] = ((fact[i - 1] % MOD) * i) % MOD;
    }
}

//[#]=============================================================[#]

int modMultiplication(int a, int b, int mod)
{
    long long res = 0;
    a %= mod;

    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }

    return res;
}

//[#]=============================================================[#]

int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}

//[#]=============================================================[#]

int binpow(int a, int b, int m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//[#]=============================================================[#]

long long binomial_coefficient(int n, int k)
{
    return fact[n] * modInverse(fact[k] * fact[n - k] % MOD, MOD) % MOD;
}

//[#]=============================================================[#]

void Solve()
{

    // (INPUT)  =====>
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = upper_bound(all(v), 35);
    auto it1 = lower_bound(all(v), 35);

    cout << v[it - v.begin()] << endl;
    cout << v[it1 - v.begin()] << endl;

    // (PRE-PROCESSING || DATA-STRUCTURES)  ===>

    // (PROCESSING)  =====>

    //(OUTPUT)  ===>
}

signed main()
{

    FastIO

        int TestCase = 1;
    // cin >> TestCase;

    // Precompute
    // SieveOfEratosthenes();

    while (TestCase--)
    {
        Solve();
    }
    return 0;
}
