#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/* 此题题目虽长，但是是最简单的贪心算法
 */
int blocks[600];
int cmp(int a, int b)
{
	return a > b;
}
int main(void)
{
	int length, n;
	while (scanf("%d%d", &length, &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &blocks[i]);
		sort(blocks, blocks + n, cmp);
		int index = 0, sum = 0;
		while (index < n && sum < length)
			sum += blocks[index++];
		if (sum >= length)
			printf("%d\n", index);
		else
			printf("impossible\n");
	}
	return 0;
}
