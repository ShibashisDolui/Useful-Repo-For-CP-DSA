#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return -1;
    else
    {

        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
    }
}

void runCases()
{
    int n;
    cin >> n;
    vector<pair<int, int>> inv;
    for (int i = 2; i < n; i++)
    {
        if (__gcd(i, n) == 1)
        {
            inv.push_back({i, modInverse(i, n)});
        }
    }
    int ans = 1;
    int count = 0;
    int p = 1;
    vector<int> temp;
    for (int i = 0; i < inv.size(); i++)
    {
        if (inv[i].first == inv[i].second)
        {
            p = (p * inv[i].first) % n;
            count++;
            temp.push_back(inv[i].first);
        }
        else
        {
            ans++;
        }
    }
    if (count % 2 == 1 && count > 1)
    {
        ans += count;
    }
    cout << ans << "\n";
    cout << 1 << " ";
    for (int i = 0; i < inv.size(); i++)
    {
        if (inv[i].first == inv[i].second)
        {
            if (count % 2 == 1 && count > 1)
            {
                cout << inv[i].first << " ";
            }
        }
        else
        {
            cout << inv[i].first << " ";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        runCases();
    }
}
