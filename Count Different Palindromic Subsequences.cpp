#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7;
    int dp[1000][1000];

    long long solve(string &s, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        long long ans = 0;
        if (s[i] == s[j])
        {
            ans += 2 * solve(s, i + 1, j - 1);
            int left = i + 1;
            int right = j - 1;
            while (left <= right && s[left] != s[i])
                left++;
            while (left <= right && s[right] != s[i])
                right--;
            if (left < right)
            { // a..a..a..a
                ans -= solve(s, left + 1, right - 1);
            }
            else if (left == right)
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
        }
        else
        {
            ans += solve(s, i + 1, j) + solve(s, i, j - 1) - solve(s, i + 1, j - 1);
        }
        return dp[i][j] = (ans % mod + mod) % mod;
    }

public:
    int countPalindromicSubsequences(string s)
    {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, s.size() - 1);
    }
};