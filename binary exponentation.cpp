#include <bits/stdc++.h>
using namespace std;

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
    return (binpow(num, p / 2, mod) * binpow(num, p / 2, mod)) % mod;
}

// from fermat's little theorem : a ^ (p - 1) congruent to 1 % p (a is not divisible by p and p is prime)
// we can rewrite B^C as k * (p - 1) + r
// so we can write A^B^C % p = A^((p - 1) * k + r) % p = (1 * A ^ r) % p = A^r % p
// r can also be written as B^C % (p - 1)

void runCases()
{
    int A, B, C, P;
    cin >> A >> B >> C >> P;
    if (A % P == 0)
    {
        if (B == 0 && C != 0)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
        return;
    }
    int temp = binpow(B, C, P - 1);
    cout << binpow(A, temp, P) << "\n";
}

int main()
{
    // sieve();
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}