#include <bits/stdc++.h>
using namespace std;

long long fact[10000001];

const int mod = 1e9 + 7;

long long binpow(long long num, long long p, const int mod)
{
    if (p == 0)
    {
        return 1;
    }
    if (p & 1)
    {
        return (num * binpow(num, p - 1, mod)) % mod;
    }
    auto res = binpow(num, p / 2, mod);
    return (res * res) % mod;
}

void calculateFactorial()
{
    fact[0] = 1;
    for (int i = 1; i <= 1e7; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

long long nCr(long long n, long long r, int mod)
{
    auto temp = fact[n - r] * fact[r];
    temp %= mod;
    return (fact[n] * binpow(temp, mod - 2, mod)) % mod;
}

void runCases()
{
    int N;
    cin >> N;
    cout << ((long long)N * (N - 3) / 2) % mod;
}

int main()
{
    calculateFactorial();
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}