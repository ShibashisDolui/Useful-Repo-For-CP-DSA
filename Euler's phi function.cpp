#include <bits/stdc++.h>
using namespace std;
#define int long long int

void runCases()
{
    int n;
    cin >> n;
    int ans = n;
    for (int i = 2; i * i <= n;)
    {
        int cnt = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            ans -= ans / i;
        }
        i = i > 2 ? i + 2 : i + 1;
    }
    if (n > 1)
    {
        ans -= ans / n;
    }
    cout << ans << "\n";
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