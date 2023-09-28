#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int countPrimeFactors(int n)
{
    int count = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        count++;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            count++;
        }
    }
    if (n > 1)
        count++;
    return count;
}

void runCases()
{
    int a, b, k;
    cin >> a >> b >> k;
    int min_steps = 0, max_steps = 0;
    if ((a % b == 0 || b % a == 0) && a != b)
    {
        min_steps = 1;
    }
    else
    {
        min_steps = 2;
    }
    max_steps = countPrimeFactors(a) + countPrimeFactors(b);
    if (k >= min_steps && k <= max_steps)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}
