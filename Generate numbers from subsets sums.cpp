#include <bits/stdc++.h>
using namespace std;
#define int long long int

void runCases()
{
    int n;
    cin >> n;
    int total = pow(2, n);
    multiset<int> subset_sums;
    for (int i = 0; i < total; i++)
    {
        int x;
        cin >> x;
        subset_sums.insert(x);
    }
    vector<int> subsets = {0};
    vector<int> nums;
    subset_sums.erase(subset_sums.begin());
    while (nums.size() < n)
    {
        int next_num = *subset_sums.begin();
        nums.push_back(next_num);
        int sz = subsets.size();
        for (int i = 0; i < sz; i++)
        {
            auto it = subset_sums.find(next_num + subsets[i]);
            subset_sums.erase(it);
            subsets.push_back(next_num + subsets[i]);
        }
    }
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";
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
