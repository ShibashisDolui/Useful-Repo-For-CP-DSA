#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool is_prime[1000001];
vector<int> primes;

void sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= 1e6; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= 1e6; i += p)
                is_prime[i] = false;
        }
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}

void segmented_sieve(int L, int R, vector<int> &res)
{
    bool check[R - L + 1];
    memset(check, true, sizeof(check));
    for (int p : primes)
    {
        int curr_mul = ((L + p - 1) / p) * p;
        while (curr_mul <= R)
        {
            if (p != curr_mul)
                check[curr_mul - L] = false;
            curr_mul += p;
        }
    }
    if (L == 1)
    {
        check[0] = false;
    }
    for (int i = 0; i < R - L + 1; i++)
    {
        if (check[i])
            res.push_back(L + i);
    }
}

void runCases()
{
    int L, R;
    cin >> L >> R;
    vector<int> res;
    segmented_sieve(L, R, res);
    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int T = 1;
    // cin >> T;
    while (T--)
    {
        runCases();
    }
}