#include <bits/stdc++.h>
using namespace std;

string calculateFraction(int num, int den)
{
    if (num == 0)
        return "0";
    int sign = (num < 0) ^ (den < 0) ? -1 : 1;
    num = abs(num);
    den = abs(den);
    int initial = num / den;
    string res;
    if (sign == -1)
        res = "-";
    res.append(to_string(initial));
    if (num % den == 0)
        return res;
    res.push_back('.');
    int rem = num % den;
    unordered_map<int, int> seen;
    int index;
    bool repeating = false;
    while (rem > 0 && !repeating)
    {
        if (seen.count(rem))
        {
            index = seen[rem];
            repeating = true;
            break;
        }
        else
            seen[rem] = res.size();
        rem = rem * 10;
        int temp = rem / den;
        res += to_string(temp);
        rem = rem % den;
    }
    if (repeating)
    {
        res.push_back(')');
        res.insert(index, "(");
    }
    return res;
}

void runCases()
{
    int num, den;
    cin >> num >> den;
    cout << calculateFraction(num, den) << "\n";
}

int main()
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