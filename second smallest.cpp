// Enter your code below
#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

void runCases()
{
    int ans = 1;
    int n;
    cin >> n;
    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num < first)
        {
            second = first;
            first = num;
        }
        else if (num < second && num != first)
        {
            second = num;
        }
    }
    if (second == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << second << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        runCases();
    }
    return 0;
}