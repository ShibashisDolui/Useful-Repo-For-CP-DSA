#include <bits/stdc++.h>
using namespace std;
#define int long long int

void runCases()
{
    string str;
    cin >> str;
    vector<set<int>> map(26);
    for (int i = 0; i < str.size(); i++)
    {
        int ch = str[i] - 'a';
        map[ch].insert(i + 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index;
            char new_ch;
            cin >> index >> new_ch;
            char old_ch = str[index - 1];
            map[old_ch - 'a'].erase(index);
            str[index - 1] = new_ch;
            map[new_ch - 'a'].insert(index);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int count = 0;
            for (int i = 0; i < 26; i++)
            {
                auto it = map[i].lower_bound(l);
                if (it != map[i].end() && *it <= r)
                {
                    count++;
                }
            }
            cout << count << "\n";
        }
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
