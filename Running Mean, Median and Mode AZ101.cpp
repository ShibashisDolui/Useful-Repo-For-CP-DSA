#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

long long binpow(long long num, long long p, const int mod)
{
    if (p == 0)
    {
        return 1;
    }
    if (p & 1)
    {
        return (num * binpow(num, p - 1, mod)) % mod;
    }
    auto res = binpow(num, p / 2, mod);
    return (res * res) % mod;
}

int modInverse(int x, int p)
{
    return binpow(x, p - 2, p);
}

class ds
{
    int sum = 0, count = 0;
    multiset<int> left, right;
    unordered_map<int, int> freq; // mode
    set<pair<int, int>> mode;     // mode

public:
    void adjust()
    {
        int diff = (int)left.size() - (int)right.size();
        if (left.size() == right.size() || diff == 1)
            return;
        if (diff > 1)
        {
            right.insert(*left.rbegin());
            left.erase(--(left.end()));
            return;
        }
        if (diff == -1)
        {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }

    void insert(int x)
    {
        // for mode
        auto it = mode.find(make_pair(freq[x], -x));
        if (it != mode.end())
        {
            mode.erase(it);
        }
        freq[x]++;
        mode.insert(make_pair(freq[x], -x));
        // for mean and median
        count++;
        sum = (sum + x) % mod;
        if (left.empty() && right.empty())
        {
            left.insert(x);
            return;
        }
        if (x > *left.rbegin())
        {
            right.insert(x);
        }
        else
        {
            left.insert(x);
        }
        adjust();
    }

    void remove(int x)
    {
        // for mode
        mode.erase(mode.find(make_pair(freq[x], -x)));
        freq[x]--;
        if (freq[x] == 0)
        {
            freq.erase(x);
        }
        else
        {
            mode.insert(make_pair(freq[x], -x));
        }
        // for mean and median
        sum = (sum - x + mod) % mod;
        count--;
        if (left.empty() && right.empty())
        {
            return;
        }
        if (x > *left.rbegin())
        {
            auto it = right.find(x);
            if (it != right.end())
            {
                right.erase(it);
            }
        }
        else
        {
            auto it = left.find(x);
            if (it != left.end())
            {
                left.erase(it);
            }
        }
        adjust();
    }

    int getMean()
    {
        if (count == 0)
        {
            return -1;
        }
        return ((sum % mod) * modInverse(count, mod)) % mod;
    }

    int getMode()
    {
        if (count == 0)
            return -1;
        return -(mode.rbegin()->second);
    }

    int getMedian()
    {
        if (left.empty() && right.empty())
            return -1;
        if (left.size() > right.size())
        {
            return *left.rbegin();
        }
        return (((*left.rbegin() + *right.begin()) % mod) * modInverse(2, mod)) % mod;
    }
};

void runCases()
{
    int q;
    cin >> q;
    ds d;
    while (q--)
    {
        string in;
        cin >> in;
        if (in == "insert")
        {
            int x;
            cin >> x;
            d.insert(x);
        }
        else if (in == "remove")
        {
            int x;
            cin >> x;
            d.remove(x);
        }
        else if (in == "getMean")
        {
            cout << d.getMean() << "\n";
        }
        else if (in == "getMode")
        {
            cout << d.getMode() << "\n";
        }
        else
        {
            cout << d.getMedian() << "\n";
        }
    }
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
