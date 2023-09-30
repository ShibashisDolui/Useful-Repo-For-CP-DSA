#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

void getFactors(int n, vector<int> &factors)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                factors.push_back(i);
                factors.push_back(n / i);
            }
            else
            {
                factors.push_back(i);
            }
        }
    }
    sort(begin(factors), end(factors));
}

void runCases()
{
    int a, b;
    cin >> a >> b;
    int gcd = __gcd(a, b);
    vector<int> factors;
    getFactors(gcd, factors);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, ans;
        cin >> l >> r;
        auto it = lower_bound(factors.begin(), factors.end(), r);
        if (it == factors.end())
        {
            ans = (*prev(it) >= l && *prev(it) <= r) ? *prev(it) : -1;
        }
        else if (*it == r)
        {
            ans = r;
        }
        else
        {
            if (it == factors.begin())
            {
                ans = (*it >= l && *it <= r) ? *it : -1;
            }
            else
            {
                ans = (*prev(it) >= l && *prev(it) <= r) ? *prev(it) : -1;
            }
        }
        cout << ans << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        runCases();
    }
}
