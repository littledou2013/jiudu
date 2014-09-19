#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 100001;
vector<int> ver[N];


bool visit[N];

int main(void)
{
	int n, m;
	int a, b;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		scanf("%d", &m);
		//注意因为是多组数据，ver[i]一定要clear()。
		for (int i = 1; i <= n; ++i)
			ver[i].clear();
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &a, &b);
			ver[a].push_back(b);
			ver[b].push_back(a);
		}
		int count = 0;
		for (int i = 1; i <= n; ++i)
			visit[i] = false;
		//使用的是广大搜索算法，也可以使用并查集
		for (int i = 1; i <= n; ++i)
		{
			if (visit[i] == false)
			{
				++count;
				visit[i] = true;
				queue<int> q;
				q.push(i);
				while (!q.empty())
				{
					int node = q.front();
					q.pop();
					int size = ver[node].size();
					for (int j = 0; j < size; ++j)
					{
						if(visit[ver[node][j]] == false)
						{
							visit[ver[node][j]] = true;
							q.push(ver[node][j]);
						}
					}

				}
			}
		}
		printf("%d\n", count);
	}
	
	return 0;

}
