#include <bits/stdc++.h>
using namespace std;
#define int long long int

void runCases()
{
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> count;
    string temp = s;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        count[s[i]]++;
    }
    string t, ans;
    for (int i = 0, j = 0; i < n && j < n; i++)
    {
        while (t.size() && t.back() <= temp[i])
        {
            ans.push_back(t.back());
            t.pop_back();
        }
        if (count[temp[i]])
        {
            while (j < n && temp[i] != s[j])
            {
                t.push_back(s[j]);
                count[s[j]]--;
                j++;
            }
            count[s[j]]--;
            ans.push_back(s[j]);
            j++;
        }
    }
    while (t.size())
    {
        ans.push_back(t.back());
        t.pop_back();
    }
    cout << ans << "\n";
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