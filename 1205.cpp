#include <iostream>
#include <cstdio>
using namespace std;
long long F[91];
int main(void)
{
	int n;
	F[0] = 0;
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i <= 90; ++i)
		F[i] = F[i-1] + F[i-2];
	while(scanf("%d", &n) != EOF)
	{
		printf("%lld\n", F[n]);
		/*
		 * 如果只有一组测试数据，下面的方式是合理的，不用开任何内存空间，就可以O(n)的方式完成
		 * 但是对于多组测试数据，则先可以计算出每一个的数字，最后直接以O(1)查询。
		 
		if (n == 0)
			printf("0\n");
		else
		{
			long long start = 1;
			long long next = 1, tmp;
			int i = 1;
			while (i < n)
			{
				tmp = start + next;
				start = next;
				next = tmp;
				++i;
			}
			printf("%lld\n", next);
		}*/
	}
	return 0;
	
}
