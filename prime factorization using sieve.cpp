#include <bits/stdc++.h>
using namespace std;

int smallest_prime_factor[10000001];

void calculateSmallestPrimeFactor()
{
    for (int i = 1; i <= 1e7; i++)
    {
        smallest_prime_factor[i] = i;
    }
    for (long long i = 2; i * i <= 1e7; i++)
    {
        if (smallest_prime_factor[i] == i)
        {
            for (long long j = i * i; j <= 1e7; j += i)
            {
                if (smallest_prime_factor[j] == j)
                {
                    smallest_prime_factor[j] = i;
                }
            }
        }
    }
}

void getPrimeFactors(int num, map<int, int> &prime_factor_count)
{
    while (num > 1)
    {
        int spf = smallest_prime_factor[num];
        int count = 0;
        while (num % spf == 0)
        {
            num /= spf;
            count++;
        }
        prime_factor_count[spf] = count;
    }
}

void runCases()
{
    int N;
    cin >> N;
    map<int, int> pfs;
    getPrimeFactors(N, pfs);
    int ans = 1;
    for (auto p : pfs)
    {
        ans *= (p.second + 1);
    }
    cout << ans << "\n";
}

int main()
{
    calculateSmallestPrimeFactor();
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}