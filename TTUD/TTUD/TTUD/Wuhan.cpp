#include<cstdio>
#include<vector>
#include<map>

//vi tri xuat hien lan thu .. cua 1 phan tu nao do

using namespace std;
map<int, vector<int> > h;
int n, m;
int main() {
	int i, a, b;
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		for (i = 1; i <= n; ++i)
		{
			scanf_s("%d", &a);
			if (h.count(a) == 0)
			{
				h[a] = vector<int>();
				h[a].push_back(0);
			}
			h[a].push_back(i);
		}
		for (i = 1; i <= m; ++i)
		{
			scanf_s("%d%d", &a, &b);
			if (h.count(b) == 0 || (h[b].size()) <= a)
				printf("0\n");
			else printf("%d\n", h[b][a]);
		}
		return 0;
	}
}
