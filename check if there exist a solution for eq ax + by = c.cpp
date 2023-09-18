#include <bits/stdc++.h>
using namespace std;

void runCases()
{
    int A, B, C;
    cin >> A >> B >> C;
    int gcd = __gcd(A, B);
    if (C % gcd == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}