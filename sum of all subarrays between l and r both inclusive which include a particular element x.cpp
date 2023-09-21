#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int totalStrength(vector<int> &str)
{
    int n = str.size();
    stack<int> s;
    vector<int> left(n, -1), right(n, -1);
    vector<long long> leftSum(n), rightSum(n), prefix(n), suffix(n);
    for (long long i = 0; i < n; i++)
    {
        prefix[i] = i > 0 ? prefix[i - 1] + str[i] : str[i];
        leftSum[i] = (i + 1) * str[i];
        if (i > 0)
        {
            leftSum[i] += leftSum[i - 1];
        }
        leftSum[i] %= mod;
        while (!s.empty() && str[i] <= str[s.top()])
        {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    s = {};
    for (long long i = n - 1; i >= 0; i--)
    {
        suffix[i] = i < n - 1 ? suffix[i + 1] + str[i] : suffix[i];
        rightSum[i] = (n - i) * str[i];
        if (i < n - 1)
        {
            rightSum[i] += rightSum[i + 1];
        }
        rightSum[i] %= mod;
        while (!s.empty() && str[i] < str[s.top()])
        {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long l, r;
        if (left[i] == -1)
        {
            l = leftSum[i];
        }
        else
        {
            l = leftSum[i] - leftSum[left[i]] - (prefix[i] - prefix[left[i]]) * (left[i] + 1);
        }
        if (right[i] == -1)
        {
            r = i + 1 < n ? rightSum[i + 1] : 0;
        }
        else
        {
            r = rightSum[i + 1] - rightSum[right[i]] - (suffix[i + 1] - suffix[right[i]]) * (n - right[i]);
        }
        l = (l % mod + mod) % mod;
        r = (r % mod + mod) % mod;
        long long rcnt = right[i] == -1 ? n - i : right[i] - i;
        long long lcnt = left[i] == -1 ? i + 1 : i - left[i];
        ans = (ans % mod + str[i] * ((l * rcnt) % mod + (r * lcnt) % mod) % mod) % mod;
        if (ans < 0)
            ans += mod;
    }
    return ans;
}

void runCases()
{
    int n;
    cin >> n;
    vector<int> str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    int ans = totalStrength(str);
    cout << ans << "\n";
}

signed main()
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