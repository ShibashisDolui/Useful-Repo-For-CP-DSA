#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

void runCases()
{
    int n, q;
    cin >> n >> q;
    vector<int> unread(n + 1), read(n + 1), visited(n + 1);
    int ans = 0;
    queue<int> notifications;
    int mark = 0;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int app;
            cin >> app;
            unread[app]++;
            ans++;
            notifications.push(app);
        }
        else if (type == 2)
        {
            int app;
            cin >> app;
            ans -= unread[app];
            read[app] += unread[app];
            unread[app] = 0;
        }
        else
        {
            int len;
            cin >> len;
            while (!notifications.empty() && mark < len)
            {
                int top = notifications.front();
                visited[top]++;
                notifications.pop();
                if (visited[top] > read[top])
                {
                    read[top]++;
                    unread[top]--;
                    ans--;
                }
                mark++;
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
    int t;
    cin >> t;
    while (t--)
    {
        runCases();
    }
}

// 1
// 2 7
// 1 1
// 1 1
// 1 2
// 2 1
// 1 1
// 1 1
// 3 2

// expected output
// 1
// 2
// 3
// 1
// 2
// 3
// 3

// original output
// 1
// 2
// 3
// 1
// 2
// 3
// 1