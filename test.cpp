#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

void nextSmallerToRight(vector<int> &arr, vector<int> &right)
{
    stack<int> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
}

void nextSmallerToLeft(vector<int> &arr, vector<int> &left)
{
    stack<int> s;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
}

void runCases()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> left(n, -1), right(n, -1);
    nextSmallerToLeft(arr, left);
    nextSmallerToRight(arr, right);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int l = left[i];
        int r = right[i];
        int curr = arr[i];
        if (l == -1 && r == -1)
        {
            mp[curr] = n;
        }
        else if (l == -1)
        {
            mp[curr] = max(mp[curr], r);
        }
        else if (r == -1)
        {
            mp[curr] = max(mp[curr], n - l - 1);
        }
        else
        {
            mp[curr] = max(mp[curr], r - l - 1);
        }
    }
    int start = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        int curr = it->first;
        int sz = it->second;
        if (sz <= start)
            continue;
        for (int i = start + 1; i <= sz; i++)
        {
            cout << curr << " ";
        }
        start = sz;
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}
