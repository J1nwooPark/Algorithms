int parent[ITEM_NUM], _size[ITEM_NUM];

int Root(int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = Root(parent[x]);
}
void Union(int x, int y)
{
	x = Root(x); y = Root(y);
	if (_size[x] > _size[y])
	{
		parent[y] = x;
		_size[x] += _size[y];
	}
	else
	{
		parent[x] = y;
		_size[y] += _size[x];
	}
}
int main()
{
    for (int i = 0; i < ITEM_NUM; i++)
    {
        parent[i] = i;
        _size[i] = 1;
    }
}
