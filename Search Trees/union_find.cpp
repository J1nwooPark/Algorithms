int parent[ITEM_NUM];

int Find(int x)
{
    if (parent[x] == x) return x;
    else
    {
        int y = Find(parent[x]);
        return y;
    }
}
void Union(int x, int y)
{
     x = Find(x);
     y = Find(y);
     parent[y] = x;
}

int main()
{
    for (int i = 0; i < ITEM_NUM; i++)
        parent[i] = i;
}
