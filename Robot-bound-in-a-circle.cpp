#include <bits/stdc++.h>
using namespace std;
#define int long long int

const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void runCases()
{
    int sz;
    cin >> sz;
    string in;
    cin >> in;
    int idx = 0, x = 0, y = 0;
    for (char i : in)
    {
        if (i == 'L')
        {
            idx = (idx + 3) % 4;
        }
        else if (i == 'R')
        {
            idx = (idx + 1) % 4;
        }
        else
        {
            x += dir[idx].first;
            y += dir[idx].second;
        }
    }
    if ((x == 0 && y == 0) || idx > 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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