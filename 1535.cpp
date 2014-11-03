#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
 * 此题启示：float,double浮点类型原来会自动四舍五入，而对于int型则需要自己处理
 */
int drug[100];
int main(void)
{
	int c;
	scanf("%d", &c);
	int n, v, w;
	while (c--)
	{
		scanf("%d%d%d", &n, &v, &w);
		for (int i = 0; i < n; ++i)
			scanf("%d", &drug[i]);
		sort(drug, drug + n);
		int sum = 0;
		int i = 0;
		while (i < n)
		{
			if ((drug[i] + sum) <= w * (i + 1))
				sum += drug[i++];
			else
				break;
		}
		/*
		 * 此题启示：float,double浮点类型原来会自动四舍五入，而对于int型则需要自己处理
		 */
		printf("%d %.2f\n", v * i, i == 0 ? sum : sum * 0.01 / i);
	}
	return 0;
}
