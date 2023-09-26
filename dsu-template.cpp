#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
    vector<vector<int>> adjList;
    vector<int> rank, parent, size;

    int find(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
        {
            return;
        }
        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            if (rank[rootA] == rank[rootB])
            {
                rank[rootA]++;
            }
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }

public:
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            rank.push_back(1);
            size.push_back(1);
        }
        adjList.resize(n + 1);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            if (!prime[u] && !prime[v])
            {
                unite(u, v);
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!prime[i])
                continue;
            vector<long long> v;
            for (int nbr : adjList[i])
            {
                if (!prime[nbr])
                {
                    int sz = size[find(nbr)];
                    ans += sz;
                    if (sz)
                        v.push_back(sz);
                }
            }
            if (v.size())
            {
                long long left = v[0];
                for (int j = 1; j < v.size(); j++)
                {
                    ans += left * v[j];
                    left += v[j];
                }
            }
        }
        return ans;
    }
};