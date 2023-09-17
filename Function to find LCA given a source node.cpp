int dfs(int src, int a, int b, int parent = -1)
{
    int count = 0;
    if (src == a || src == b)
    {
        count++;
    }
    for (int nbr : g[src])
    {
        if (nbr != parent)
        {
            int x = dfs(nbr, a, b, src);
            if (x >= 0)
            {
                return x;
            }
            if (x == -1)
            {
                count++;
            }
        }
    }
    if (count == 2)
        return src;
    if (count == 1)
        return -1;
    return -2;
}