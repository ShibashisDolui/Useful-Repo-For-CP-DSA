#include <bits/stdc++.h>
using namespace std;
// #define int long long int

void add(int value, map<int, int> &intervals)
{
    if (intervals.count(value))
    {
        return;
    }
    auto it = intervals.upper_bound(value);
    if (it == intervals.end())
    {
        intervals[value] = value;
        if (intervals.count(value - 1))
        {
            intervals[value] = intervals[value - 1];
            intervals.erase(value - 1);
        }
        return;
    }
    if (it->second < value)
    {
        return;
    }
    if (it->second > value + 1)
    {
        intervals[value] = value;
        if (intervals.count(value - 1))
        {
            intervals[value] = intervals[value - 1];
            intervals.erase(value - 1);
        }
        return;
    }
    if (it->second == value + 1)
    {
        it->second = value;
    }
    if (intervals.count(value - 1))
    {
        it->second = intervals[value - 1];
        intervals.erase(value - 1);
    }
}

void runCases()
{
    int N, R, C, X, Y;
    string in;
    cin >> N >> R >> C >> X >> Y >> in;
    int i = X, j = Y;
    // cout << in;
    vector<map<int, int>> row(R + 1), col(C + 1);
    row[i][j] = j;
    col[j][i] = i;
    int next_i, next_j;
    for (char next : in)
    {
        if (next == 'E')
        {
            auto it = row[i].lower_bound(j);
            if (it->first == j)
            {
                next_i = i;
                next_j = j + 1;
            }
            else
            {
                next_i = i;
                next_j = it->first + 1;
            }
        }
        else if (next == 'W')
        {
            auto it = row[i].lower_bound(j);
            next_i = i;
            next_j = it->second - 1;
        }
        else if (next == 'S')
        {
            auto it = col[j].lower_bound(i);
            if (it->first == i)
            {
                next_i = i + 1;
                next_j = j;
            }
            else
            {
                next_i = it->first + 1;
                next_j = j;
            }
        }
        else
        {
            auto it = col[j].lower_bound(i);
            next_i = it->second - 1;
            next_j = j;
        }
        add(next_j, row[next_i]);
        add(next_i, col[next_j]);
        i = next_i;
        j = next_j;
    }
    cout << i << " " << j << "\n";
}

int_fast32_t main()
{
    cout << fixed << setprecision(7);
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}