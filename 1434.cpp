#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
 * 找准贪心策略
 */
struct Channel
{
	int start, end;
	bool operator < (const Channel &channel) const
	{
		return end < channel.end;
	}
};

Channel channel[100];
int main(void)
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &channel[i].start, &channel[i].end);
		sort(channel, channel + n);
		int end = 0;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (channel[i].start >= end)
			{
				++count;
				end = channel[i].end;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
