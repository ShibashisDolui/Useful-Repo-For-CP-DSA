#include <bits/stdc++.h>
using namespace std;
#define int long long int

int fact[100001];

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
    for (int i = 1; i <= 1e5; i++)
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

int modInverse(int x, int p)
{
    return binpow(x, p - 2, p);
}

void calculateDearrangements(int n, vector<int> &D)
{
    D[0] = 1;
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            sum -= modInverse(fact[i], mod);
        }
        else
        {
            sum += modInverse(fact[i], mod);
        }
        sum = (sum % mod + mod) % mod;
        D[i] = (sum * fact[i]) % mod;
    }
}

void runCases()
{
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> D(n + 1);
    D[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    calculateDearrangements(n, D);
    int q;
    cin >> q;
    vector<int> ans(n + 1);
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + (nCr(n, n - i, mod) * D[i]) % mod;
        ans[i] %= mod;
        // cout << ans[i] << " ";
    }
    while (q--)
    {
        int k;
        cin >> k;
        cout << ans[k] << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    calculateFactorial();
    int T = 1;
    // cin >> T;
    while (T--)
    {
        runCases();
    }
}